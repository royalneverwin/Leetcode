class Solution {
public:
    typedef pair<double, double> pair;
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for(int i = 0; i < points.size()-2; i++){
            for(int j = i+1; j < points.size()-1; j++){
                for(int k = j+1; k < points.size(); k++){
                    pair vec1 = make_pair(points[j][0] - points[i][0], points[j][1] - points[i][1]);
                    pair vec2 = make_pair(points[k][0] - points[i][0], points[k][1] - points[i][1]);

                    double S = fabs(vec1.first * vec2.second  - vec2.first * vec1.second);

                    ans = max(ans, S);
                }
            }
        }


        return ans / 2.0;
    }
};