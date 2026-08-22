import os

SIDE_1 = "jtd"
SIDE_2 = "cep"
SIDE_3 = "ilb"
SIDE_4 = "hyw"


def is_valid(w, face, status):
    if len(w) < 3:
        return False, 0
    prev_side = -1
    value = 0
    new_status = []
    for e in status:
        new_status.append(e[:])
    for c in w:
        for side in range(4):
            if side != prev_side and c in face[side]:
                prev_side = side
                c_idx = face[side].index(c)
                if not new_status[side][c_idx]:
                    new_status[side][c_idx] = True
                    value += 1
                break
        else:
            return False, 0
    return True, value


def covers(lst, flat):
    return set("".join(lst)) == flat


def words():
    lst = []
    dictionary_path = os.path.join("/content/words.txt")
    with open(dictionary_path, 'r') as file:
        for row in file:
            lst.append(row.strip())
    return lst


def main():
    face_letters = [list(SIDE_1), list(SIDE_2), list(SIDE_3), list(SIDE_4)]
    flat_list = set([item for sublist in face_letters for item in sublist])
    face_status = [[False]*3 for _ in range(4)]
    universe = []

    for word in words():
        ok, v = is_valid(word, face_letters, face_status)
        if ok:
            universe.append(word)

    for w0 in universe:
        if covers([w0], flat_list):
            print("SINGLE WORD ---> " + w0)

    for w1 in universe:
        for w2 in universe:
            if w1[-1] == w2[0] and covers([w1, w2], flat_list):
                print(" + ".join([w1, w2]))

main()

#

import os

SIDE_1 = ""
SIDE_2 = ""
SIDE_3 = ""
SIDE_4 = ""


def is_valid(w, face, status):
    if len(w) < 4:
        return False, 0
    prev_side = -1
    value = 0
    new_status = []
    for e in status:
        new_status.append(e[:])
    for c in w:
        for side in range(4):
            if side != prev_side and c in face[side]:
                prev_side = side
                c_idx = face[side].index(c)
                if not new_status[side][c_idx]:
                    new_status[side][c_idx] = True
                    value += 1
                break
        else:
            return False, 0
    return True, value


def covers(lst, flat):
    return set("".join(lst)) == flat


def words():
    lst = []
    dictionary_path = os.path.join("/content/words.txt")
    with open(dictionary_path, 'r') as file:
        for row in file:
            lst.append(row.strip())
    return lst


def main():
    face_letters = [list(SIDE_1), list(SIDE_2), list(SIDE_3), list(SIDE_4)]
    flat_list = set([item for sublist in face_letters for item in sublist])
    face_status = [[False]*4 for _ in range(4)]
    universe = []

    for word in words():
        ok, v = is_valid(word, face_letters, face_status)
        if ok:
            universe.append(word)

    for w0 in universe:
        if covers([w0], flat_list):
            print("SINGLE WORD ---> " + w0)

    for w1 in universe:
        for w2 in universe:
            if w1[-1] == w2[0] and covers([w1, w2], flat_list):
                print(" + ".join([w1, w2]))

main()

# Final Version For The Bonus Part Version

import os

SIDE_1 = "apeh"
SIDE_2 = "bsut"
SIDE_3 = "cdlr"
SIDE_4 = "iomn"


def is_valid(w, face, status):
    if len(w) < 4:
        return False, 0
    prev_side = -1
    value = 0
    new_status = []
    for e in status:
        new_status.append(e[:])
    for c in w:
        for side in range(4):
            if side != prev_side and c in face[side]:
                prev_side = side
                c_idx = face[side].index(c)
                if not new_status[side][c_idx]:
                    new_status[side][c_idx] = True
                    value += 1
                break
        else:
            return False, 0
    return True, value


def covers(lst, flat):
    return set("".join(lst)) == flat


def words():
    lst = []
    dictionary_path = os.path.join("/content/words.txt")
    with open(dictionary_path, 'r') as file:
        for row in file:
            lst.append(row.strip())
    return lst


def main():
    face_letters = [list(SIDE_1), list(SIDE_2), list(SIDE_3), list(SIDE_4)]
    flat_list = set([item for sublist in face_letters for item in sublist])
    face_status = [[False]*4 for _ in range(4)]
    universe = []

    for word in words():
        ok, v = is_valid(word, face_letters, face_status)
        if ok:
            universe.append(word)

    for w0 in universe:
        if covers([w0], flat_list):
            print("SINGLE WORD ---> " + w0)
	z=0
    for w1 in universe:
        for w2 in universe:
            if w1[-1] == w2[0] and covers([w1, w2], flat_list):
				z+=1
                asss=" + ".join([w1, w2])
	if z==1:
		print(asss)

