class Solution {
public:
    double r, x, y;
    default_random_engine generator;
    
    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {
        
    }
    
    vector<double> randPoint() {
        #define PI 3.1415926
        uniform_real_distribution<double> angle_distribution(-PI, PI);
        uniform_real_distribution<double> radius_distribution(0, 1);
        double angle = angle_distribution(generator);
        double rad = r * sqrt(radius_distribution(generator));
        return { x + rad * cos(angle), y + rad * sin(angle) };        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */