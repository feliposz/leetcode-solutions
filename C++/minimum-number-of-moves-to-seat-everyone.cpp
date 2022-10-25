class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int sz = seats.size();
        int moves = 0;
        for (int i = 0; i < sz; i++) {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};