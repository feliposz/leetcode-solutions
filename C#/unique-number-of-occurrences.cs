public class Solution {
    public bool UniqueOccurrences(int[] arr) {
        Dictionary<int,int> count = new();
        foreach (int n in arr) {
            if (!count.ContainsKey(n)) {
                count[n] = 0;
            }
            count[n]++;
        }
        HashSet<int> seen = new();
        foreach (var (_, n) in count) {
            if (seen.Contains(n)) {
                return false;
            }
            seen.Add(n);
        }
        return true;
    }
}