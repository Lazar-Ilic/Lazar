import collections

class FrogGameSimulator:
    def __init__(self, size, start_pos):
        if not (0 <= start_pos[0] < size and 0 <= start_pos[1] < size):
            raise ValueError("Start position is off board.")

        self.size = size
        self.board = [['W' for _ in range(size)] for _ in range(size)]
        self.frog_pos = tuple(start_pos)
        
        self.board[self.frog_pos[0]][self.frog_pos[1]] = 'B'
        self.white_cells_count = size * size - 1
        
        self.moves_made = [] # Stores move characters: ['A', 'B', ...]
        # Stores tuples of (prev_frog_pos, landed_cell_pos, 
        #                  next_next_cell_pos, original_color_of_next_next_cell)
        self.history_stack = [] 

        self.move_deltas = collections.OrderedDict([
            ('A', (0, 1)),  # Right
            ('B', (1, 1)),  # Down-Right
            ('C', (1, 0)),  # Down
            ('D', (1, -1)), # Down-Left
            ('E', (0, -1)), # Left
            ('F', (-1, -1)),# Up-Left
            ('G', (-1, 0)),  # Up
            ('H', (-1, 1))  # Up-Right
        ])
        self.possible_move_chars = list(self.move_deltas.keys())

    def _is_valid_rc(self, r, c):
        return 0 <= r < self.size and 0 <= c < self.size

    def get_cell_color(self, r, c):
        if not self._is_valid_rc(r, c):
            return None # Off-board
        return self.board[r][c]

    def display_board(self):
        #print("-" * (self.size * 2 + 1))
        for r in range(self.size):
            row_str = ""
            for c in range(self.size):
                char_to_display = self.board[r][c]
                if (r, c) == self.frog_pos:
                    char_to_display = 'F' # Show Frog's current position
                row_str += char_to_display
            print(row_str)
            #print("-" * (self.size * 2 + 1))
        print(f"Frog at: {self.frog_pos}")
        print(f"Moves: {''.join(self.moves_made)}")
        print(f"White cells remaining: {self.white_cells_count}")
        if self.is_solved():
            print("Congratulations! Board is fully colored!")

    def make_move(self, move_char):
        move_char = move_char.upper()
        if move_char not in self.move_deltas:
            print(f"Invalid move character: {move_char}. Valid moves are {self.possible_move_chars}.")
            return False

        dr, dc = self.move_deltas[move_char]
        r0, c0 = self.frog_pos  # Current frog position

        r1, c1 = r0 + dr, c0 + dc  # Target cell P1
        r2, c2 = r1 + dr, c1 + dc  # Next cell in direction P2

        # Condition 1: P1 must be on board and white
        if not self._is_valid_rc(r1, c1):
            print(f"Move {move_char}: Target cell ({r1},{c1}) is off board.")
            return False
        if self.board[r1][c1] != 'W':
            print(f"Move {move_char}: Target cell ({r1},{c1}) is {self.board[r1][c1]}, not White.")
            return False

        # Condition 2: P2 (if it exists) must not be blue
        p2_color = self.get_cell_color(r2, c2) # Handles off-board P2 returning None
        if p2_color == 'B':
            print(f"Move {move_char}: Cell after target ({r2},{c2}) is Blue, which is not allowed.")
            return False

        # --- If move is valid, proceed ---
        
        # Store state for take_back
        p2_original_color_before_reddening = p2_color if self._is_valid_rc(r2,c2) else None # Store W or R, or None if P2 off-board
        self.history_stack.append( (self.frog_pos, (r1,c1), 
                                     (r2,c2) if self._is_valid_rc(r2,c2) else None, 
                                     p2_original_color_before_reddening) )

        # Update P1 (target cell)
        # P1 was 'W', now becomes 'B'
        self.board[r1][c1] = 'B'
        self.white_cells_count -= 1
        
        # Update P2 (cell after target)
        if self._is_valid_rc(r2, c2):
            if self.board[r2][c2] == 'W': # P2 was 'W', now 'R'
                self.white_cells_count -= 1
            self.board[r2][c2] = 'R' # Becomes R or stays R

        # Update frog position and moves list
        self.frog_pos = (r1, c1)
        self.moves_made.append(move_char)
        
        # print(f"Move {move_char} to ({r1},{c1}) successful.")
        return True

    def take_back(self):
        if not self.history_stack:
            print("No moves to take back.")
            return False

        prev_frog_pos, p1_landed_on, p2_affected, p2_original_color = self.history_stack.pop()
        
        r1, c1 = p1_landed_on # This cell was made 'B', originally 'W'
        
        # Revert P1
        self.board[r1][c1] = 'W'
        self.white_cells_count += 1
        
        # Revert P2
        if p2_affected:
            r2, c2 = p2_affected
            current_p2_color = self.board[r2][c2] # Should be 'R'
            
            if current_p2_color == 'R' and p2_original_color == 'W':
                self.white_cells_count += 1 # Restoring a white cell that became red
            
            self.board[r2][c2] = p2_original_color # Restore to W or R
            
        # Restore frog position and remove last move
        self.frog_pos = prev_frog_pos
        last_move_char = self.moves_made.pop()
        
        print(f"Took back move {last_move_char}. Frog back at {self.frog_pos}.")
        return True

    def is_solved(self):
        return self.white_cells_count == 0

    def get_moves_string(self):
        return "".join(self.moves_made)

    def play_interactive(self):
        print("Welcome to the Frog Game Simulator!")
        self.display_board()
        while True:
            if self.is_solved():
                print("Game solved!")
                break
            
            print("\nPossible moves: A, B, C, D, E, F, G, H")
            print("Enter move char, 'takeback', 'reset', or 'exit'.")
            user_input = input("Your move: ").strip().lower()

            if user_input == 'exit':
                print("Exiting simulator.")
                break
            elif user_input == 'takeback':
                self.take_back()
                self.display_board()
            elif user_input == 'reset':
                # Find initial start_pos from first history item if exists or re-initialize
                # For simplicity, this example reset would need the initial start_pos stored or passed again.
                # A simple reset to initial condition:
                r_init, c_init = self.history_stack[0][0] if self.history_stack else self.frog_pos # This is not quite right.
                                                                                               # Need original start_pos
                print("Resetting game (feature basic - re-init with first frog_pos if history not empty or current if empty).")
                # This reset is partial. For a full reset, we'd need to re-init the class instance.
                # For now, let's make it simpler: take back all moves.
                while self.history_stack:
                    self.take_back()
                self.display_board()

            elif len(user_input) == 1 and user_input.upper() in self.move_deltas:
                if self.make_move(user_input.upper()):
                    self.display_board()
                else:
                    # Error messages are printed within make_move
                    self.display_board() # Show board again even if move failed
            else:
                print("Invalid input.")

# --- Example Usage ---
if __name__ == "__main__":
    # --- Interactive Mode for 10x10 bonus as an example ---
    # To try the 10x10 board starting from (4,4):
    # game_10x10 = FrogGameSimulator(size=10, start_pos=(4,4))
    # game_10x10.play_interactive()

    # --- Example from problem description (4x4, (0,0)) ---
    # Note: As discussed, the example "ABHCDBEFDGH" might conflict with rules.
    # Let's trace the example string if provided, but with rule checks.
    print("\n--- Testing 4x4 example from description (with strict rule checks) ---")
    game_4x4_test = FrogGameSimulator(size=4, start_pos=(0,0))
    example_moves = "ABHCDBEFDGH"
    print(f"Initial board for 4x4 at (0,0):")
    game_4x4_test.display_board()
    
    # For testing, we can try to apply the example sequence
    # This is for demonstration; a direct solution search is complex.
    # for i, move in enumerate(example_moves):
    #     print(f"\nAttempting move {i+1}: {move}")
    #     if not game_4x4_test.make_move(move):
    #         print(f"Move {move} failed. Current board state:")
    #         game_4x4_test.display_board()
    #         print("Stopping example trace due to invalid move under current rules.")
    #         break
    #     game_4x4_test.display_board()
    # if game_4x4_test.get_moves_string() == example_moves:
    #     print("\nSuccessfully traced the example sequence under current rules.")
    #     print(f"Final board for 4x4 with sequence {game_4x4_test.get_moves_string()}:")
    #     game_4x4_test.display_board()
    #     print(f"Number of red cells: {sum(row.count('R') for row in game_4x4_test.board)}")


    # To start a new game for manual solving (e.g., 20x20 or 10x10):
    # print("\n--- Starting a new game for interactive play ---")
    # try:
    #     board_size_input = int(input("Enter board size (e.g., 10 for 10x10): "))
    #     start_r_input = int(input(f"Enter start row (0 to {board_size_input-1}): "))
    #     start_c_input = int(input(f"Enter start col (0 to {board_size_input-1}): "))
    #     interactive_game = FrogGameSimulator(size=board_size_input, start_pos=(start_r_input, start_c_input))
    #     interactive_game.play_interactive()
    # except ValueError as e:
    #     print(f"Error setting up game: {e}")
    # except Exception as e:
    #     print(f"An unexpected error occurred: {e}")
        
    # Default to starting the 10x10 game for the bonus.
    print("\n--- Starting interactive game for 10x10 board at (4,4) (Bonus) ---")
    try:
        game_10x10_bonus = FrogGameSimulator(size=10, start_pos=(4,4))
        game_10x10_bonus.play_interactive()
    except ValueError as e:
        print(f"Error starting 10x10 game: {e}")

# ADADADADCHCHCHCAGAGFEHAFEHAFHGDGEDCFGDFCBDADCDCDBEFGHFAFAFAFAFAHE