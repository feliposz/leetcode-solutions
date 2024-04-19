func minimumMoves(s string) int {
    x, o, moves := 0, 0, 0
    for _, c := range s {
        if c == 'X' {
            x++
        } else if x > 0 {
            o++
        }
        if x > 0 && x + o == 3 {
            moves++
            x = 0
            o = 0
        }
    }
    if x > 0 {
        moves++
    }
    return moves
}