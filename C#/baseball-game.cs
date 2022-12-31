public class Solution {
    public int CalPoints(string[] operations) {
        var points = new List<int>();

        int total = 0;

        foreach (string op in operations) {
            switch (op) {
                case "+": {
                    int x = points[points.Count - 1] + points[points.Count - 2];
                    points.Add(x);
                    total += x;
                }
                break;

                case "D": {
                    int x = points[points.Count - 1] * 2;
                    points.Add(x);
                    total += x;
                }
                break;
                    
                case "C": {
                    int x = points[points.Count - 1];
                    points.RemoveAt(points.Count - 1);
                    total -= x;
                }
                break;

                default: {
                    int x = Convert.ToInt32(op);
                    points.Add(x);
                    total += x;
                }
                break;
            }
        }

        return total;
    }
}