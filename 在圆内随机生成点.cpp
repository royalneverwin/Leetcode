class Solution {
    double r;
    double x;
    double y;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
public:
    Solution(double radius, double x_center, double y_center) {
        dis = uniform_real_distribution<double>(-radius, radius);
        r = radius;
        x = x_center;
        y = y_center;
    }

    // 两种方法 很简单
    // 第一种在外接正方形上生成随机点 不在圆内就扔掉
    // 第二种考虑分布密度函数，F(r) = r^2，所以在[0, r^2]中随机
    vector<double> randPoint() {
        while(1) {
            double rx =dis(gen);
            double ry = dis(gen);
            if((rx) * (rx) + (ry) * (ry) <= r * r) {
                return vector<double>{rx + x, ry + y};
            }
        }
    }
};



class Solution {
    double r;
    double x;
    double y;
    int cnt;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
        cnt = 1;
    }

    // 两种方法 很简单
    // 第一种在外接正方形上生成随机点 不在圆内就扔掉
    // 第二种考虑分布密度函数，F(r) = r^2，所以在[0, r^2]中随机
    vector<double> randPoint() {
        srand (cnt);
        cnt++;
        while(1) {
            double rx = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (2.0 * r))) - r;
            double ry = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (2.0 * r))) - r;
            if((rx) * (rx) + (ry) * (ry) <= r * r) {
                return vector<double>{rx + x, ry + y};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */