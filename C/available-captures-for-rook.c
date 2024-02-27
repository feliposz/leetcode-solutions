int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int rook_row = -1, rook_col = -1;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] == 'R') {
                rook_row = row;
                rook_col = col;
                break;
            }
        }
        if (rook_row != -1) {
            break;
        }
    }

    int available = 0;

    for (int col = rook_col + 1; col < 8; col++) {
        char cell = board[rook_row][col];
        if (cell == 'p') {
            available++;
            break;
        } else if (cell == 'B') {
            break;
        }        
    }
    for (int col = rook_col - 1; col >= 0; col--) {
        char cell = board[rook_row][col];
        if (cell == 'p') {
            available++;
            break;
        } else if (cell == 'B') {
            break;
        }        
    }    
    for (int row = rook_row + 1; row < 8; row++) {
        char cell = board[row][rook_col];
        if (cell == 'p') {
            available++;
            break;
        } else if (cell == 'B') {
            break;
        }        
    }
    for (int row = rook_row - 1; row >= 0; row--) {
        char cell = board[row][rook_col];
        if (cell == 'p') {
            available++;
            break;
        } else if (cell == 'B') {
            break;
        }        
    }

    return available;
}