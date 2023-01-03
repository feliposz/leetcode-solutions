public class Solution {
    public IList<int> TwoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        var values = new Dictionary<int,int>();

        foreach (int i in nums1) {
            if (!values.ContainsKey(i)) {
                values[i] = 0;
            }
            values[i] |= 1;
        }
        foreach (int i in nums2) {
            if (!values.ContainsKey(i)) {
                values[i] = 0;
            }
            values[i] |= 2;
        }
        foreach (int i in nums3) {
            if (!values.ContainsKey(i)) {
                values[i] = 0;
            }
            values[i] |= 4;
        }

        var result = new List<int>();
        foreach (var p in values) {
            if (p.Value == 3 || p.Value == 5 || p.Value == 6 || p.Value == 7) {
                result.Add(p.Key);
            }
        }
        return result;
    }
}