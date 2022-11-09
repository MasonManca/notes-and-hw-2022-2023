
class NimPlayer:
   def __init__(self):
      pass

   def play(self, board):
      # search every option for recommended
      for row, sticks in enumerate(board):
         test_board = board.copy()
         for leave in range(sticks):
            test_board[row] = leave
            if self.int_sum(test_board) != 0 and self.recommend(test_board):
               board[row] = leave
               return board
      # none recommended, take 1 from 1st row
      return self.take_first(board)

   def int_sum(self, board):
      int_sum = 0
      for sticks in board:
         int_sum += sticks
      return int_sum

   def recommend(self, board):
      for outer_row, outer_sticks in enumerate(board):
         outer_board = board.copy()
         for outer_leave in range(outer_sticks):
            outer_board[outer_row] = outer_leave

            for inner_row, inner_sticks in enumerate(outer_board):
               inner_board = outer_board.copy()
               for inner_leave in range(inner_sticks):
                  inner_board[inner_row] = inner_leave
                  if self.int_sum(inner_board) == 1:
                     return False
      return True

   def take_first(self, board):
      for row, sticks in enumerate(board):
         if sticks > 0:
            board[row] -= 1
            return board
      print("ERROR: No stick taken")

