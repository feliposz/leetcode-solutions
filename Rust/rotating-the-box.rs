impl Solution {
    pub fn rotate_the_box(box_grid: Vec<Vec<char>>) -> Vec<Vec<char>> {
        let m = box_grid.len();
        let n = box_grid[0].len();

        // rotate by transposing + flipping horizontally
        let mut box_rot: Vec<Vec<char>> = (0..n)
            .map(|i| (0..m).map(|j| box_grid[m - j - 1][i]).collect())
            .collect();

        // simulate gravity
        for j in 0..m {
            let mut moved = true;
            while moved {
                moved = false;
                for i in (1..n).rev() {
                    if box_rot[i][j] == '.' && box_rot[i - 1][j] == '#' {
                        box_rot[i][j] = '#';
                        box_rot[i - 1][j] = '.';
                        moved = true;
                    }
                }
            }
        }
        box_rot
    }
}