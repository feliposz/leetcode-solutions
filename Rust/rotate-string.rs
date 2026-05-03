impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            return false;
        }
        let s = s.as_bytes();
        let goal = goal.as_bytes();
        for shift in 0..s.len() {
            let mut equals = true;
            for (i, c) in s.iter().enumerate() {
                let j = (i + shift) % s.len();
                if *c != goal[j] {
                    equals = false;
                    break;
                }
            }
            if equals {
                return true;
            }
        }
        false
    }
}