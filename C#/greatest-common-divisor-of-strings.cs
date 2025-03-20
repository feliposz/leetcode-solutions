public class Solution {

    // Optimal solution
    public string GcdOfStrings(string a, string b) {
        if (a + b != b + a) {
            return "";
        }
        return a.Substring(0, GCD(a.Length, b.Length));
    }

    static int GCD(int a, int b)
    {
        return b == 0 ? a : GCD(b, a % b);
    }

    // Adapted Euclide's Algorithm version
    public string Euclides_GcdOfStrings(string a, string b) {
        if (a.Length < b.Length) {
            return GcdOfStrings(b, a);
        }
        if (a == b) {
            return a;
        }
        if (a.StartsWith(b)) {
            return GcdOfStrings(a.Substring(b.Length), b);
        }
        return "";
    }

    // Naive approach, trying every possible base
    public string Naive_GcdOfStrings(string a, string b) {
        string x = a.Length < b.Length ? a : b;
        while (x.Length > 0 ) {
            if (a.Length % x.Length == 0 && b.Length % x.Length == 0) {
                int ratioA = a.Length / x.Length;
                int ratioB = b.Length / x.Length;
                var sa = new StringBuilder();
                var sb = new StringBuilder();
                for (int i = 0; i < ratioA; i++) {
                    sa.Append(x);
                }
                for (int i = 0; i < ratioB; i++) {
                    sb.Append(x);
                }
                if (sa.ToString() == a && sb.ToString() == b) {
                    break;
                }
            }
            x = x.Substring(0, x.Length - 1);
        }
        return x;
    }
}