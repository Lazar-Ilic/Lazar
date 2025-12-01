import copy
from collections import deque
from typing import List, Tuple, Dict, Optional

Vec = Tuple[int, int, int]

def _vec_neg(a: Vec) -> Vec:
    return (-a[0], -a[1], -a[2])

def _vec_eq(a: Vec, b: Vec) -> bool:
    return a[0]==b[0] and a[1]==b[1] and a[2]==b[2]

def _cross(a: Vec, b: Vec) -> Vec:
    ax, ay, az = a; bx, by, bz = b
    return (ay*bz - az*by, az*bx - ax*bz, ax*by - ay*bx)

def _sign_between(a: Vec, b: Vec) -> Optional[int]:
    """+1 if a==b, -1 if a==-b, else None."""
    if _vec_eq(a, b): return +1
    if _vec_eq(a, _vec_neg(b)): return -1
    return None

class _Face:
    def __init__(self, name: str, size_u: int, size_v: int, e_u: Vec, e_v: Vec):
        self.name = name
        self.size_u = size_u
        self.size_v = size_v
        self.e_u = e_u
        self.e_v = e_v
        self.n = _cross(e_u, e_v) # outward normal

def _build_faces(a: int, b: int, c: int):
    Xp=(1,0,0); Xm=(-1,0,0)
    Yp=(0,1,0); Ym=(0,-1,0)
    Zp=(0,0,1); Zm=(0,0,-1)
    faces = [
        _Face('XY+', a,b, Xp, Yp), # 0
        _Face('XY-', a,b, Xp, Ym), # 1
        _Face('XZ+', a,c, Xp, Zm), # 2
        _Face('XZ-', a,c, Xp, Zp), # 3
        _Face('YZ+', b,c, Yp, Zp), # 4
        _Face('YZ-', b,c, Ym, Zp), # 5
    ]
    normal_to_id = {faces[i].n: i for i in range(6)}
    return faces, normal_to_id

def _rot90(h: Vec, v: Vec, sign: int) -> Vec:
    """Rotate v by ±90° about axis h (right-hand rule). If v || h, leave unchanged."""
    if _sign_between(v, h) is not None:
        return v
    hv = _cross(h, v)
    return hv if sign > 0 else _vec_neg(hv)

def _within(face: _Face, u: int, v: int) -> bool:
    return 0 <= u < face.size_u and 0 <= v < face.size_v

def _neighbor_mapping(faces, normal_to_id, face_id: int, edge_axis: str, edge_sign: int, u: int, v: int):
    """Cross an edge from (face_id, u, v) stepping out along axis edge_axis with sign edge_sign."""
    f = faces[face_id]
    cross_vec = f.e_u if edge_axis == 'u' else f.e_v
    cross_vec = cross_vec if edge_sign > 0 else _vec_neg(cross_vec)
    hinge = f.e_v if edge_axis == 'u' else f.e_u
    target_normal = (
        f.e_u if (edge_axis == 'u' and edge_sign > 0) else
        _vec_neg(f.e_u) if edge_axis == 'u' else
        f.e_v if (edge_axis == 'v' and edge_sign > 0) else
        _vec_neg(f.e_v)
    )
    n = f.n
    cand = _rot90(hinge, n, +1)
    rot_sign = +1 if _vec_eq(cand, target_normal) else -1
    nbr_face_id = normal_to_id[target_normal]
    nbr = faces[nbr_face_id]

    if (sh := _sign_between(nbr.e_u, hinge)) is not None:
        hinge_axis_on_nbr = 'u'; hinge_sign_on_nbr = sh
        size_hinge, size_perp = nbr.size_u, nbr.size_v
        axis_vec_perp = nbr.e_v
    else:
        sh = _sign_between(nbr.e_v, hinge)
        hinge_axis_on_nbr = 'v'; hinge_sign_on_nbr = sh
        size_hinge, size_perp = nbr.size_v, nbr.size_u
        axis_vec_perp = nbr.e_u

    idx_h_cur = v if edge_axis == 'u' else u
    idx_h_nbr = idx_h_cur if hinge_sign_on_nbr > 0 else (size_hinge - 1 - idx_h_cur)
    c_rot = _rot90(hinge, cross_vec, rot_sign)
    s_perp = _sign_between(c_rot, axis_vec_perp)
    idx_perp_nbr = 0 if s_perp > 0 else (size_perp - 1)

    if hinge_axis_on_nbr == 'u':
        u_new, v_new = idx_h_nbr, idx_perp_nbr
    else:
        u_new, v_new = idx_perp_nbr, idx_h_nbr

    return nbr_face_id, u_new, v_new, hinge, rot_sign

def _try_map(poly: List[List[int]],
             dims: Tuple[int, int, int],
             seed_cell: Tuple[int, int],
             start_face_id: int,
             start_corner: Tuple[int, int],
             ori: Tuple[Tuple[str,int], Tuple[str,int]]) -> Optional[Dict]:
    a,b,c = dims
    faces, normal_to_id = _build_faces(a,b,c)
    H, W = len(poly), len(poly[0])

    cells = [(r,cx) for r in range(H) for cx in range(W) if poly[r][cx] == 1]
    cell_set = set(cells)
    surface_total = 2*(a*b + b*c + c*a)
    if len(cells) != surface_total:
        return None

    q = deque([seed_cell]); seen = {seed_cell}
    while q:
        r,cx = q.popleft()
        for dr,dc in ((1,0),(-1,0),(0,1),(0,-1)):
            nb = (r+dr, cx+dc)
            if nb in cell_set and nb not in seen:
                seen.add(nb); q.append(nb)
    if seen != cell_set:
        return None

    start_u, start_v = start_corner
    if not _within(faces[start_face_id], start_u, start_v):
        return None

    (axis_e, sign_e), (axis_s, sign_s) = ori
    t_e = faces[start_face_id].e_u if axis_e == 'u' else faces[start_face_id].e_v
    t_s = faces[start_face_id].e_u if axis_s == 'u' else faces[start_face_id].e_v
    t_e = t_e if sign_e > 0 else _vec_neg(t_e)
    t_s = t_s if sign_s > 0 else _vec_neg(t_s)

    cell_to_place: Dict[Tuple[int,int], Tuple[int,int,int,Vec,Vec]] = {}
    place_to_cell: Dict[Tuple[int,int,int], Tuple[int,int]] = {}
    dq = deque()
    cell_to_place[seed_cell] = (start_face_id, start_u, start_v, t_e, t_s)
    place_to_cell[(start_face_id, start_u, start_v)] = seed_cell
    dq.append(seed_cell)

    while dq:
        r,cx = dq.popleft()
        face_id, u, v, t_e, t_s = cell_to_place[(r,cx)]
        f = faces[face_id]

        def dir_to_face(dr: int, dc: int) -> Tuple[str,int]:
            vec = (
                t_e if (dr,dc)==(0,1) else
                _vec_neg(t_e) if (dr,dc)==(0,-1) else
                t_s if (dr,dc)==(1,0) else
                _vec_neg(t_s)
            )
            su = _sign_between(vec, f.e_u)
            if su is not None: return ('u', su)
            sv = _sign_between(vec, f.e_v)
            if sv is not None: return ('v', sv)
            raise RuntimeError("Bad dir")

        for dr,dc in ((0,1),(0,-1),(1,0),(-1,0)):
            nb = (r+dr, cx+dc)
            if nb not in cell_set:
                continue
            axis, sign = dir_to_face(dr,dc)
            du = (1 if sign>0 else -1) if axis=='u' else 0
            dv = (1 if sign>0 else -1) if axis=='v' else 0
            u2, v2 = u+du, v+dv

            if _within(f, u2, v2):
                nbr_face_id = face_id
                new_te, new_ts = t_e, t_s
                coord = (nbr_face_id, u2, v2)
            else:
                nbr_face_id, u2, v2, hinge, rot_sign = _neighbor_mapping(
                    faces, normal_to_id, face_id, axis, sign, u, v
                )
                new_te = _rot90(hinge, t_e, rot_sign)
                new_ts = _rot90(hinge, t_s, rot_sign)
                coord = (nbr_face_id, u2, v2)

            if coord in place_to_cell:
                if place_to_cell[coord] != nb:
                    return None
                pfid, pu, pv, pte, pts = cell_to_place[nb]
                if not (pfid==coord[0] and pu==coord[1] and pv==coord[2] and pte==new_te and pts==new_ts):
                    return None
                continue

            if nb not in cell_to_place:
                cell_to_place[nb] = (coord[0], coord[1], coord[2], new_te, new_ts)
                place_to_cell[coord] = nb
                dq.append(nb)
            else:
                pfid, pu, pv, pte, pts = cell_to_place[nb]
                if not (pfid==coord[0] and pu==coord[1] and pv==coord[2] and pte==new_te and pts==new_ts):
                    return None

    if len(place_to_cell) != 2*(dims[0]*dims[1] + dims[1]*dims[2] + dims[0]*dims[2]):
        return None

    return {'place_to_cell': place_to_cell, 'faces': _build_faces(*dims)[0]}

def _enumerate_attempts(poly: List[List[int]], dims: Tuple[int,int,int]):
    a,b,c = dims
    faces, _ = _build_faces(a,b,c)
    H, W = len(poly), len(poly[0])
    cells = [(r,cx) for r in range(H) for cx in range(W) if poly[r][cx]==1]
    surface_total = 2*(a*b + b*c + c*a)
    if len(cells) != surface_total:
        return []
    areas = [faces[i].size_u*faces[i].size_v for i in range(6)]
    face_order = sorted(range(6), key=lambda i: (-areas[i], i))
    corners = {i: [(0,0), (faces[i].size_u-1,0), (0,faces[i].size_v-1), (faces[i].size_u-1,faces[i].size_v-1)] for i in range(6)}
    oris = []
    for axis_e in ('u','v'):
        for sign_e in (+1,-1):
            other = 'v' if axis_e=='u' else 'u'
            for sign_s in (+1,-1):
                oris.append(((axis_e, sign_e), (other, sign_s)))
    for seed in cells:
        for fid in face_order:
            for corner in corners[fid]:
                for ori in oris:
                    yield seed, fid, corner, ori

def label_grid_by_face(grid: List[List[int]], prism_dims: Tuple[int,int,int]):
    """Return (ok, label_grid, legend) with each '1' tile labeled 1..6 by face."""
    H, W = len(grid), len(grid[0])
    for seed, fid, corner, ori in _enumerate_attempts(grid, prism_dims):
        res = _try_map(grid, prism_dims, seed, fid, corner, ori)
        if res is None:
            continue
        place_to_cell = res['place_to_cell']
        faces = res['faces']
        face_to_num = {i: i+1 for i in range(6)} # 0..5 -> 1..6
        legend = {i+1: faces[i].name for i in range(6)}
        labeled = [[0]*W for _ in range(H)]
        for (face_id, u, v), (r, c) in place_to_cell.items():
            labeled[r][c] = face_to_num[face_id]
        return True, labeled, legend
    return False, None, None

def print_grid(g):
    for row in g:
        print(' '.join(str(x) for x in row))

lolol = [0 for a in range(7)]
sol = [[0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,3,3,0],
[0,0,0,0,0,0,0,6,6,0,6,6,0,0,0,5,5,5,5,5],
[0,0,0,0,0,0,0,6,0,0,0,6,6,0,2,5,0,5,0,0],
[0,0,0,0,0,0,0,6,6,0,6,6,6,2,2,0,0,5,5,5],
[0,0,0,0,0,0,0,0,6,6,6,0,6,2,0,0,0,5,0,5],
[0,0,0,0,0,0,6,6,6,0,0,0,6,2,0,0,0,5,0,0],
[0,0,0,0,0,0,6,6,6,6,0,6,6,0,0,0,0,5,5,0],
[0,0,1,1,1,1,4,4,4,0,0,4,4,2,0,0,0,4,4,4],
[0,1,1,1,0,0,4,4,0,0,0,4,4,2,2,2,0,4,4,0],
[0,0,5,5,0,1,5,5,5,0,0,5,0,5,5,0,0,6,0,0],
[0,0,0,0,0,1,5,5,5,5,0,5,0,0,0,0,6,6,6,0],
[0,0,6,6,0,0,0,5,0,5,0,5,5,0,0,0,6,0,0,0],
[0,0,0,6,0,0,0,5,0,0,0,5,5,0,0,0,0,0,0,0],
[0,0,0,6,1,0,5,5,5,5,0,5,0,0,0,0,0,0,0,0],
[0,0,0,6,1,1,5,5,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,3,3,3,0,0,3,3,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,6,0,0,6,2,2,0,0,0,0,0],
[0,0,0,0,0,0,0,0,6,6,6,0,0,2,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0]]
vals=[[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0],
[0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,7,0,5,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,4,0,0,7,0,0,0,4,0,0],
[0,0,0,0,0,0,4,0,7,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0],
[0,0,7,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0],
[0,0,0,0,0,4,0,7,0,0,0,0,0,0,0,0,0,0,3,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,5,0,0,6,0,0,2,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
countt=0
countsum=0
for a in range(20):
     for b in range(20):
          if vals[a][b]>0:
               countt+=1
               countsum+=vals[a][b]
          if vals[a][b]>0 and sol[a][b]==0:
               print("ERROR")
          if sol[a][b]>0:
               lolol[sol[a][b]]+=vals[a][b]
answer = 1
for a in range(1,7):
     answer *= lolol[a]
print("Answer ", answer, countt, countsum, lolol)

PRISM_DIMS = (1, 2, 4)
GRID_01 = [
    [0,0,1,1,0,0,0,0],
    [1,1,1,1,1,1,0,0],
    [0,0,1,1,0,1,1,1],
    [1,1,1,1,0,0,0,0],
    [0,0,0,1,0,0,0,0],
    [0,0,1,1,1,1,1,0],
    [1,1,1,1,0,1,0,0]
]

ok, labeled, legend = label_grid_by_face(GRID_01, PRISM_DIMS)
print("Folds:", ok)
if ok:
    print("Legend (number -> face):", legend)
    print("Labeled grid:")
    print_grid(labeled)

if __name__ == "__main__":
	dims = []
	for a in range(1,100):
		for b in range(a,100):
			for c in range(b,100):
				if 2*(a*b+b*c+c*a)>=131 and 2*(a*b+b*c+c*a)<=139:
					dims.append([a,b,c])
	grids = []
	grid = [
		[0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0],
		[0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1,1],
		[0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,0,1,0,0],
		[0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,1,1,0],
		[0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,0],
		[0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,0],
		[0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,1,0],
		[0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1],
		[0,1,1,1,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0],
		[0,0,1,1,0,1,1,1,1,0,0,1,0,1,1,0,0,1,0,0],
		[0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,1,1,0],
		[0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,1,0,0,0],
		[0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0],
		[0,0,0,1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0],
		[0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0],
		[0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0],
		[0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0],
		[0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0],
		[0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0],
		[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0]
	]
	for a in range(3):
		for b in range(2):
			for c in range(2):
				for d in range(3):
					for e in range(2):
						newgrid=copy.deepcopy(grid)
						if a>=1:
							newgrid[0][6]=1
						if a>=2:
							newgrid[0][5]=1
						if b>=1:
							newgrid[0][17]=1
						if c==0:
							newgrid[1][16]=1
						else:
							newgrid[2][16]=1
						if d>=1:
							newgrid[3][19]=1
						if d>=2:
							newgrid[4][19]=1
						if e>=1:
							newgrid[17][15]=1
						grids.append(newgrid)
	print(len(dims))
	print(len(grids))
	dims=[[2,6,7]]
	for dim in dims:
		print(dim)
		z=1
		for grid in grids:
			print(z)
			z+=1
			precheck = False
			counter = 0
			for dude0 in grid:
				for dude1 in dude0:
					counter += dude1
			if 2*(dim[0]*dim[1]+dim[1]*dim[2]+dim[2]*dim[0]) == counter:
				precheck = True
			if precheck:
				ok, labeled, legend = label_grid_by_face(grid,dim)
				if ok:
					print(labeled)