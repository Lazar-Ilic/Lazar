# Can you write a simulator in Python I can play which tracks the path string, enables undos, and also shows both the GP and max eatable value, as well as the location of the cube at all times?
# Now in the print out position of the board force 2 digits for each value.

import math
import copy

initial_board = [[0,1,0,0,0,5,16,8,15,4,5,5,17,17,7,11,18,4,16,15,9,17,1,3,19,6,4,16,3,7],[6,3,13,11,1,5,10,18,8,18,8,8,3,10,18,4,2,8,3,1,11,12,11,15,12,8,14,5,4,9],[9,0,15,4,1,11,1,11,17,8,4,6,4,12,16,19,9,8,4,2,18,12,1,4,4,10,10,4,9,2],[10,10,2,9,1,19,19,16,19,18,2,4,17,6,8,1,14,9,13,4,1,4,10,2,11,2,7,8,10,15],[11,6,14,1,0,8,4,9,3,16,6,6,14,9,5,19,13,5,5,0,17,18,8,17,6,4,5,17,5,15],[0,1,0,0,7,1,8,0,4,3,3,5,10,16,2,9,18,17,17,6,14,15,13,12,1,8,15,1,9,1],[0,1,1,0,19,4,1,0,13,4,4,6,3,11,11,1,19,17,12,7,16,17,0,18,0,14,17,18,17,18],[16,14,5,1,3,0,18,12,15,7,2,0,2,2,8,13,3,9,13,13,18,3,1,12,18,19,1,6,16,0],[7,13,15,9,0,1,4,15,8,3,19,12,4,0,2,1,11,19,6,3,0,14,5,15,7,4,3,15,10,15],[19,16,11,8,3,2,10,13,10,14,11,12,10,18,6,2,7,9,11,10,4,14,10,6,11,4,12,5,17,10],[9,0,10,19,19,11,14,19,17,3,4,8,11,4,3,6,8,12,4,8,4,3,16,10,4,10,12,10,19,0],[18,17,1,17,19,5,3,10,10,19,17,6,6,14,3,2,8,5,1,2,8,10,7,4,18,10,5,3,9,6],[10,16,0,17,11,10,14,1,11,1,2,14,16,4,8,2,10,2,8,8,18,12,18,13,18,1,17,18,8,2],[2,11,8,11,12,15,0,5,8,3,4,6,6,7,6,15,7,7,13,18,13,12,14,9,15,0,15,8,1,7],[2,6,17,14,5,14,0,8,1,11,13,13,19,13,5,1,8,9,18,5,1,16,14,11,9,2,12,18,10,19],[15,2,15,17,8,5,11,18,16,10,7,1,17,18,19,9,4,13,12,6,3,2,4,5,0,13,13,17,19,12],[17,4,4,17,8,14,6,12,18,14,13,7,17,5,19,18,9,11,11,10,6,17,19,6,13,19,7,0,14,5],[8,9,10,2,19,3,7,10,9,14,16,3,6,4,1,15,13,8,5,0,14,8,6,0,1,3,14,1,13,10],[12,3,10,18,5,19,17,16,5,12,14,19,6,13,15,3,1,15,15,4,10,9,12,2,19,3,10,13,12,2],[19,18,17,19,2,18,16,5,6,4,12,10,0,1,5,12,10,18,3,0,3,12,14,2,16,13,9,15,10,15],[17,5,19,16,14,6,2,15,9,14,19,15,7,15,16,6,12,1,8,12,2,14,12,18,4,4,4,12,12,17],[6,12,7,17,0,11,17,11,5,12,13,6,4,13,15,16,9,16,15,3,13,11,3,17,14,9,5,5,5,12],[3,0,4,15,16,4,17,2,2,16,0,1,7,4,3,0,4,2,9,13,13,4,15,10,16,0,1,5,1,2],[6,1,9,6,9,9,8,18,2,5,2,9,19,0,12,7,0,17,4,3,19,10,12,14,10,8,6,6,10,19],[6,11,13,2,17,11,3,1,18,13,12,0,11,7,2,12,9,3,13,8,2,1,17,19,11,19,5,0,2,15],[13,19,12,17,9,18,13,9,1,12,6,9,15,13,9,3,4,4,0,15,15,4,16,9,16,13,1,13,4,6],[17,5,11,3,3,15,9,16,8,1,15,14,9,12,13,8,17,1,16,7,15,17,18,8,11,16,19,14,7,8],[6,10,18,16,4,10,2,14,6,2,1,1,18,0,6,17,6,15,17,0,5,13,11,4,8,10,8,1,10,13],[13,0,3,2,9,14,3,5,14,11,4,13,0,8,5,14,14,8,19,7,14,10,16,14,8,19,19,2,6,19],[5,3,4,5,10,19,2,5,8,10,9,6,11,4,4,12,10,15,17,15,8,9,5,19,14,16,12,16,16,5]] # [[0,0,1,5,1,0,0,0,0,0,1,19,0,7,4,2,7,12,7,1],[2,6,0,0,1,8,0,8,1,2,1,0,8,9,1,7,10,13,10,6],[4,11,6,7,5,5,14,1,12,1,0,2,0,2,2,5,1,10,0,14],[15,12,2,5,18,6,19,16,18,11,14,3,1,2,3,3,8,2,1,9],[5,6,8,18,4,17,7,16,14,13,4,13,8,1,2,2,7,5,11,12],[6,7,13,16,1,14,7,17,18,9,14,6,16,10,0,3,2,0,6,5],[11,5,11,3,14,19,19,4,17,16,3,12,17,17,1,2,12,6,7,11],[18,6,6,3,19,13,7,9,5,13,4,4,2,13,2,0,0,5,4,6],[17,19,7,2,4,3,4,1,16,9,13,17,17,15,6,9,1,5,2,0],[8,8,17,18,10,12,10,0,0,13,13,10,8,0,0,7,18,10,6,3],[13,3,19,3,5,9,17,16,12,2,19,9,1,17,3,0,10,11,4,19],[14,5,11,13,15,6,5,10,6,1,7,3,4,15,10,10,13,4,9,7],[2,12,5,7,7,16,3,2,18,14,11,18,12,15,4,2,12,15,10,6],[12,5,2,15,8,9,18,9,5,1,17,17,1,0,8,9,5,6,8,13],[9,13,5,3,9,8,18,15,10,6,12,18,11,15,2,12,6,8,12,15],[14,4,2,0,13,2,18,12,16,2,4,13,0,3,16,15,15,16,7,7],[6,12,1,14,4,12,8,14,10,0,15,16,13,4,5,12,5,2,16,12],[5,5,3,0,8,0,5,16,11,4,17,13,18,17,0,9,8,16,13,6],[15,13,13,5,6,7,9,15,12,18,2,12,19,4,9,5,6,8,9,3],[12,10,11,2,5,8,11,7,16,12,0,14,10,5,9,0,15,4,11,3]]

# RRDRRURRRRDRRUDDLRRDRRRRDLLRRUULLRRDDDDLDDDRLUURRRURULULURULULLLURRRRRRDLLRRDDLDRDDDLDDDDDDDDDDDDRUUUUUUUUUUULLDDDDDDDDDDDLUUUUUUUUUUUUUULDDDDDDDDDDDDDDLUUUUUUUUULUUUUULULDDRDDDDDRDLDDRDDDDDLLURUULDUUUUUUUUUUUUUUUURLULLLLLLLLLLDLDRRRRRUDRRRDRRDDDDDDDDDDDDDDDDLUUUUUUUUUUUUUUUULLLLLLLLLDDDDDDDDDDDDDDDDRRRRRRRRUUUUUUUUUUUUUUULLLLLLLDDDDDDDDDDDDDDRRRRRRUUUUUUUUUUUUULLLLLDDDDDDDDDDDRRRRUUUUUUUUUULLLDDDDDDDDDDDLRRRRLUUUUUUUUUULDDDDDDDDD
# RRRRDDDDLDLLDRRDRDDRURLUURRURRRRUUURULULLRDDDDDDRRRRUULUUUDDRRRDRUUUURDDDDDLLLDDRURRDRRURULURRDRDDDRURURUURRDDDDDDLLLDLDLLLLLDLD

dirs = {
    'U': (-1, 0),
    'D': (1, 0),
    'L': (0, -1),
    'R': (0, 1)
}

def size_from_gp(gp):
    return int(math.isqrt(gp))

def display_board(board, pos):
    for r in range(len(board)):
        row = ''
        for c in range(len(board[0])):
            if (r, c) == pos:
                row += '[K]'
            else:
                row += f' {board[r][c]:02} '
        print(row)
    print()

def get_max_eatable(board, size):
    max_val = 0
    for row in board:
        for val in row:
            if 0 < val <= size:
                max_val = max(max_val, val)
    return max_val

class GameState:
    def __init__(self, board):
        self.board = copy.deepcopy(board)
        self.path = ''
        self.pos = (0, 0)
        self.gp = 1
        self.history = []

    def current_size(self):
        return size_from_gp(self.gp)

    def move(self, direction):
        if direction not in dirs:
            print("Invalid direction! Use U, D, L, R.")
            return

        dr, dc = dirs[direction]
        nr, nc = self.pos[0] + dr, self.pos[1] + dc

        if not (0 <= nr < len(self.board) and 0 <= nc < len(self.board[0])):
            print("Move out of bounds!")
            return

        target = self.board[nr][nc]
        if target > self.current_size():
            print(f"Too big to eat! Object size: {target}, Your size: {self.current_size()}")
            return

        self.history.append((copy.deepcopy(self.board), self.pos, self.gp, self.path))

        self.gp += target
        self.board[nr][nc] = 0
        self.pos = (nr, nc)
        self.path += direction

    def undo(self):
        if not self.history:
            print("No moves to undo!")
            return
        self.board, self.pos, self.gp, self.path = self.history.pop()

    def status(self):
        print("--- Game Status ---")
        print(f"Position: {self.pos}")
        print(f"GP: {self.gp}")
        print(f"Size: {self.current_size()}")
        print(f"Max eatable object: {get_max_eatable(self.board, self.current_size())}")
        print(f"Path: {self.path}")
        print("Board:")
        display_board(self.board, self.pos)

def main():
    game = GameState(initial_board)
    print("Welcome to Klumpengeist Simulator!")
    print("Move with U/D/L/R. Type 'undo' to undo, 'exit' to quit.")
    while True:
        game.status()
        cmd = input("Your move: ").strip().upper()
        if cmd == 'EXIT':
            break
        elif cmd == 'UNDO':
            game.undo()
        elif cmd in dirs:
            game.move(cmd)
        else:
            print("Unknown command.")

if __name__ == '__main__':
    main()