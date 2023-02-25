class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool done = false;
        while (!done) {
            done = true;
            for (int i = 1; i < asteroids.size(); i++) {
                if (asteroids[i-1] > 0 && asteroids[i] < 0) {
                    if (asteroids[i-1] == -asteroids[i]) {
                        asteroids.erase(asteroids.begin() + i);
                        asteroids.erase(asteroids.begin() + i - 1);
                    } else if (asteroids[i-1] < -asteroids[i]) {
                        asteroids.erase(asteroids.begin() + i - 1);
                    } else {
                        asteroids.erase(asteroids.begin() + i);
                    }
                    i--;
                    done = false;
                }
            }
        }
        return asteroids;
    }
};