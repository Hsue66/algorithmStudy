# -*- coding: utf8 -*-

total_case = input()
case_index = 0
case_count = 0


def cover_all(board):
    if not board:
        return True
    for cells in board:
        for cell in cells:
            if cell is '.':
                return False
    return True


def in_range(board, row, column):
    if not board or row >= len(board) or column >= len(board[0]):
        return False
    if board[row][column] == '#':
        return False
    return True


def find_first_placce(board):
    for row_idx in xrange(len(board)):
        for column_idx in xrange(len(board[row_idx])):
            if board[row_idx][column_idx] == '.':
                row = row_idx
                column = column_idx
                return row, column
    return 0, 0


def board_cover(board):
    if cover_all(board):
        global case_count
        case_count += 1
        return
    # find first place that is '.'
    row, column = find_first_placce(board)
    if in_range(board, row, column + 1) and in_range(board, row + 1, column + 1):
        # ㄱ
        __board = [list(row_cells) for row_cells in board]
        __board[row][column] = '#'
        __board[row][column + 1] = '#'
        __board[row + 1][column + 1] = '#'
        board_cover(__board)
    if in_range(board, row, column + 1) and in_range(board, row + 1, column):
        # ㄱ 반전
        __board = [list(row_cells) for row_cells in board]
        __board[row][column] = '#'
        __board[row][column + 1] = '#'
        __board[row + 1][column] = '#'
        board_cover(__board)
    if in_range(board, row + 1, column) and in_range(board, row + 1, column + 1):
        # ㄴ
        __board = [list(row_cells) for row_cells in board]
        __board[row][column] = '#'
        __board[row + 1][column] = '#'
        __board[row + 1][column + 1] = '#'
        board_cover(__board)
    if in_range(board, row + 1, column - 1) and in_range(board, row + 1, column):
        # ㄴ 반전
        __board = [list(row_cells) for row_cells in board]
        __board[row][column] = '#'
        __board[row + 1][column - 1] = '#'
        __board[row + 1][column] = '#'
        board_cover(__board)


while case_index < total_case:
    case_count = 0
    row, column = [int(x) for x in raw_input().split()]

    board = []
    board = [list(raw_input()) for x in xrange(row)]
    if not cover_all(board):
        board_cover(board)
    print case_count
    case_index += 1
