public class Solution {
    public bool UniqueOccurrences(int[] arr) {
        var seen = new Dictionary<int,int>();

        foreach (int x in arr) {
            if (!seen.ContainsKey(x)) {
                seen[x] = 0;
            }
            seen[x]++;
        }

        var occur = new HashSet<int>();

        foreach (var p in seen) {
            if (occur.Contains(p.Value)) {
                return false;
            } else {
                occur.Add(p.Value);
            }
        }

        return true;
    }
}