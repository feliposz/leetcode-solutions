public class Solution {
    public int MinimumRounds(int[] tasks) {
        var group = new Dictionary<int,int>();
        foreach (int t in tasks) {
            if (!group.ContainsKey(t))
                group[t] = 0;
            group[t]++;
        }
        int rounds = 0;
        foreach (var p in group) {
            if (p.Value < 2) {
                return -1;
            } else {
                int r = p.Value % 3;
                if (r == 0) {
                    rounds += p.Value / 3;
                } else {
                    rounds += p.Value / 3 + 1;
                }
            }
        }
        return rounds;
    }
}