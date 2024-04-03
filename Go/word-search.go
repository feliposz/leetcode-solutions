func exist(board [][]byte, word string) bool {
    var search func (row, col, pos int) bool
    search = func (row, col, pos int) bool {
        if pos == len(word) {
            return false
        }
        if word[pos] != board[row][col] {
            return false
        }
        if pos == len(word) - 1 {
            return true
        }
        saved := board[row][col]    
        board[row][col] = '.'
        if row > 0 && search(row - 1, col, pos + 1) {
            return true
        }
        if row < len(board) - 1 && search(row + 1, col, pos + 1) {
            return true
        }
        if col > 0 && search(row, col - 1, pos + 1) {
            return true
        }
        if col < len(board[0]) - 1 && search(row, col + 1, pos + 1) {
            return true
        }
        board[row][col] = saved
        return false
    }

    for row, boardRow := range board {
        for col := range boardRow {
            if search(row, col, 0) {                
                return true
            }
        }
    }
    return false
}
