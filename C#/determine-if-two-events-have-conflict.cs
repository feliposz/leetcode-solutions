public class Solution {
    public bool HaveConflict(string[] event1, string[] event2) {
        int s1 = ConvertTime(event1[0]),
            e1 = ConvertTime(event1[1]),
            s2 = ConvertTime(event2[0]),
            e2 = ConvertTime(event2[1]);
        return Intersect(s1, s2, e2)
            || Intersect(e1, s2, e2)
            || Intersect(s2, s1, e1)
            || Intersect(e2, s1, e1);
    }

    private int ConvertTime(string s) {
        return Convert.ToInt32(s.Substring(0, 2)) * 100 + Convert.ToInt32(s.Substring(3, 2));
    }

    private bool Intersect(int x, int s, int e) {
        return s <= x && x <= e;
    }
}