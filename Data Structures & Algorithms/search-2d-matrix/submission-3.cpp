class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = matrix.size()*matrix[0].size()-1;
        while( start <= end ){
            int mid = start + (end - start)/2;
            int midval = matrix[mid/col][mid%col];
            if( midval > target ){
                end = mid - 1;
            }
            else if( midval < target ){
                start = mid + 1;
            }
            else{
                return true;
            }
        }        
        return false;
    }
};
