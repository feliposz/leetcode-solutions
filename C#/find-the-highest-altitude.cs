public class Solution {
    public int LargestAltitude(int[] gain) {
        int top = 0;
        int alt = 0;
        foreach (int delta in gain) {
            alt += delta;
            top = Math.Max(alt, top);
        }
        return top;
    }
}