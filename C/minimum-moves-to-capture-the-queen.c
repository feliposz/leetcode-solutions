int sign(int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    if (a == e) { // rook is at the same column
        if (c != e) // bishop is on different column
            return 1;
        else if (b < f && (d > f || d < b)) // rook is above queen, bishop is below queen or above rook
            return 1;
        else if (b > f && (d < f || d > b)) // rook is below queen, bishop is above queen or below rook
            return 1;
        // bishop is blocking rook, so must move it first
    }
    
    if (b == f) { // rook is at the same row
        if (d != f) // bishop is on different row
            return 1;
        else if (a < e && (c > e || c < a)) // rook is left of queen, bishop is right of queen or left of rook
            return 1;
        else if (a > e && (c < e || c > a)) // rook is right of queen, bishop is left of queen or right of rook
            return 1;
        // bishop is blocking rook, so must move it first
    }

    // bishop distances
    int bdx = c - e; // - left + right
    int bdy = d - f; // - up + down

    // rook distances
    int rdx = a - e;
    int rdy = b - f;

    if (abs(bdx) == abs(bdy)) { // bishop and queen form a diagonal (1 move)
        if (abs(rdx) != abs(rdy)) // rook and queen does not form a diagonal (rook can't block bishop)
            return 1;
        else if (sign(bdx) != sign(rdx) || sign(bdy) != sign(rdy)) // rook and bishop are not on the same diagonal
            return 1;
        else if (bdx > 0 && rdx > bdx) // if bishop is to the right of queen, make sure rook is more to the right
            return 1;
        else if (bdx < 0 && rdx < bdx) // if bishop is to the left of queen, make sure rook is more to the left
            return 1;
    }

    // rook needs at most 2 moves
    return 2;
}