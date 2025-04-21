public class Solution {
    public int Compress(char[] chars) {
        int i = 0;
        int dest = 0;
        int size = chars.Length;
        while (i < size) {
            int count = 0;
            while (i + count < size && chars[i] == chars[i + count]) {
                count++;
            }
            chars[dest++] = chars[i];
            if (count > 1) {
                foreach (char c in count.ToString()) {
                    chars[dest++] = c;
                }
            }
            i += count;
        }
        return dest;
    }
}