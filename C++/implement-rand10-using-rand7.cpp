// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result = 0;
        do {
            result = rand7() + (rand7() - 1) * 7;
        } while (result > 40);
        return (result - 1) % 10 + 1;
    }
};