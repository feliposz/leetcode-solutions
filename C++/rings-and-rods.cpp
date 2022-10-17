class Solution {
public:
    int countPoints(string rings) {
        int sz = rings.length();
        vector<int> rods(10);
        for (int i = 0; i < sz; i += 2) {
            int color = rings[i] == 'R' ? 1 : (rings[i] == 'G' ? 2 : 4);
            int rod = rings[i+1] - '0';
            rods[rod] |= color;
        }
        int count = 0;
        for (int rod: rods) {
            if (rod == 7) count++;
        }
        return count;
    }
};