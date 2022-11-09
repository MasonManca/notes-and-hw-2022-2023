# Mason Manca
# CPSC 323
# Prof. Morehead
# 27 October 2022
# Project 8: Multi Nim Player (Revision)
import functools
import numpy as np

class NimPlayer:
   def __init__(self):
      pass

   def play(self, boardstate):
      boardstate = np.array(boardstate)

      for row, sticks in enumerate(boardstate):
         temp = boardstate.copy()

         for leave in range(sticks):
            temp[row] = leave

            if (find_winning_move(temp)):
               boardstate[row] = leave

               return list(boardstate)

      largestRow = np.argmax(boardstate)
      boardstate[largestRow] += -1

      return list(boardstate)


def find_largest_row(boardstate):
 
   myNimSum = NIM_SUM(boardstate)

   for rowIndex in range(len(boardstate)):

      rowSize = boardstate[rowIndex]
      temp = Xor(rowSize, myNimSum)

      if (temp < rowSize):

         return rowIndex # stops when finds largest row on board

def Xor(a, b):
        
   result = (a ^ b) # Xor bitwise operator

   return int(result)

def NIM_SUM(boardstate):

   nim_sum = functools.reduce(lambda a, b: a ^ b, boardstate, 0)

   return nim_sum

def number_of_sticks(boardstate):
   number_of_sticks = 0
   for sticks in boardstate:
      number_of_sticks += sticks
   return number_of_sticks


def find_winning_move(boardstate):
   for num_rows, num_sticks in enumerate(boardstate):
      temp_board_1 = boardstate.copy()

      for bad_rows in range(num_sticks):
         temp_board_1[num_rows] = bad_rows

         for col_rows, col_sticks in enumerate(temp_board_1):
            temp_board_2 = temp_board_1.copy()

            for col_bad_row in range(col_sticks):
               temp_board_2[col_rows] = col_bad_row

               if number_of_sticks(temp_board_2) == 1:
                  return False
   return True


