class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> people(num_people);
        
        int i = 0;
        int n = 0;
        while (candies > 0) {
            n = min(n + 1, candies);
            people[i++ % num_people] += n;
            candies -= n;
        }
        
        return people;
    }
};