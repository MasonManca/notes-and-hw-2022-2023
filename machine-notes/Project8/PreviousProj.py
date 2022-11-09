# Mason Manca
# CPSC 323
# Prof. Morehead
# 20 October 2022
# Project 7: Multi-Nim Player

# Board state ex. [1,3,5,7,9,11,13,15,17]
import functools
import numpy as np

class NimPlayer():
    def __init__(self):
        pass

    def play(self,boardstate):
        new_board = findWinningMove(boardstate)

        return new_board
    
def Xor(a, b):
    
    result = (a ^ b) # Xor bitwise operator

    return int(result)

def NIM_SUM(boardstate):

    nim_sum = functools.reduce(lambda a, b: a ^ b, boardstate, 0)

    return nim_sum


def isWinning(boardstate):
    # Checks to see if the nimsum is not 0

    winning = NIM_SUM(boardstate) != 0

    return winning


def find_largest_row(boardstate):

    myNimSum = NIM_SUM(boardstate)

    for rowIndex in range(len(boardstate)):

        rowSize = boardstate[rowIndex]
        temp = Xor(rowSize, myNimSum)

        if (temp < rowSize):

            return rowIndex # stops when finds largest row on board


def findWinningMove(boardstate):

    board = np.array(boardstate)

    # no winning move
    if (not isWinning(boardstate)):
        # taking from largest row

        largestRowNumber = np.argmax(board)

        rowNumber = largestRowNumber

    # the position is winning
    else:
        largestRow = find_largest_row(boardstate)       
 
        rowNumber = largestRow
        newRowSize = Xor(NIM_SUM(boardstate), boardstate[rowNumber])

    rowNext = board.copy()
    # Could determine the most sticks that could be tkaen at this point to find nim sum of 0

    rowNext[rowNumber] += -1

    return list(rowNext)

boardstate = [1,3,5,3]

boardstate = find_largest_row(boardstate)
print(boardstate)