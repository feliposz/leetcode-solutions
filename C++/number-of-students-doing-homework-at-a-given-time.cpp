class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int sz = startTime.size();
        int students = 0;
        for (int i = 0; i < sz; i++) {
            if ((startTime[i] <= queryTime) && (queryTime <= endTime[i])) {
                students++;
            }
        }
        return students;
    }
};