class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        row, col = click
        if board[row][col] == 'M':
            board[row][col] = 'X'
        else:
            self.reveal(board, row, col)
        return board

    def reveal(self, board: List[List[str]], row: int, col: int) -> None:
        if row < 0 or row > len(board) - 1:
            return
        if col < 0 or col > len(board[0]) - 1:
            return
        if board[row][col] == 'E':
            mines = self.countMines(board, row, col)
            if mines > 0:
                board[row][col] = str(mines)
            else:
                board[row][col] = 'B'
                self.reveal(board, row - 1, col)
                self.reveal(board, row + 1, col)
                self.reveal(board, row, col - 1)
                self.reveal(board, row, col + 1)
                self.reveal(board, row - 1, col - 1)
                self.reveal(board, row - 1, col + 1)
                self.reveal(board, row + 1, col - 1)
                self.reveal(board, row + 1, col + 1)

    def countMines(self, board: List[List[str]], row: int, col: int) -> int:
        rows = len(board)
        cols = len(board[0])
        mines = 0
        if row > 0:
            if board[row-1][col] == 'M':
                mines += 1
            if col > 0 and board[row-1][col-1] == 'M':
                mines += 1
            if col < cols - 1 and board[row-1][col+1] == 'M':
                mines += 1
        if row < rows - 1:
            if board[row+1][col] == 'M':
                mines += 1
            if col > 0 and board[row+1][col-1] == 'M':
                mines += 1
            if col < cols - 1 and board[row+1][col+1] == 'M':
                mines += 1
        if col > 0:
            if board[row][col-1] == 'M':
                mines += 1
        if col < cols - 1:
            if board[row][col+1] == 'M':
                mines += 1
        return mines