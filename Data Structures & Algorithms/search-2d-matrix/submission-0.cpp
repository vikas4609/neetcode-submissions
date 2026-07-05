class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left_x = 0;
        int left_y = 0;
        int right_x = m-1;
        int right_y = n-1;
        while(left_x <= right_x && left_y <= right_y){
            int mid_x = (left_x+right_x)/2;
            int mid_y = (left_y+right_y)/2;
            if(matrix[mid_x][mid_y] == target){
                return true;
            }else if(matrix[mid_x][mid_y] > target){
                if(target >= matrix[mid_x][0]){
                    right_y = mid_y-1;
                }else{
                    right_x = mid_x-1;
                }
            }else {
                if(target <= matrix[mid_x][n-1]){
                    left_y = mid_y+1;
                }else{
                    left_x = mid_x+1;
                }
            }
        }
        return false;
    }
};
