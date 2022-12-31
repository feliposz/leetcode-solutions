public class Solution {
    public double[] ConvertTemperature(double celsius) {
        var temp = new double[2];
        temp[0] = celsius + 273.15;
        temp[1] = celsius * 1.8 + 32.0;
        return temp;
    }
}