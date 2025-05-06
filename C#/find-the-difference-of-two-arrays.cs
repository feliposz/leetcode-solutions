public class Solution {
    public IList<IList<int>> FindDifference(int[] nums1, int[] nums2) {
        HashSet<int> uniq1 = new(nums1);
        HashSet<int> uniq2 = new(nums2);
        List<int> result1 = new();
        List<int> result2 = new();
        foreach (int x in uniq1) {
            if (!uniq2.Contains(x)) {
                result1.Add(x);
            }
        }
        foreach (int x in uniq2) {
            if (!uniq1.Contains(x)) {
                result2.Add(x);
            }
        }
        return new List<IList<int>>() {result1, result2};
    }
}