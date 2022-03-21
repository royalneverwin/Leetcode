class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0] > target)
            return false;
        int index;
        for(index = 0; index < matrix.size() - 1; index++){
            if(matrix[index][0] <= target && matrix[index+1][0] > target){
                break;
            }
        }
        if(index == matrix.size() - 1){
            if(matrix[index][matrix[index].size()-1] < target){
                return false;
            }
        }
        if(find(matrix[index].begin(), matrix[index].end(), target) != matrix[index].end())
            return true;
        else
            return false;
    }
};