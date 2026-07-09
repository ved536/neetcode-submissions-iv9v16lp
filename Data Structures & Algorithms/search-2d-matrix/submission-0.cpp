class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for( int i = 0; i < matrix.size(); i++){
            int start = 0;
            int end = matrix[i].size()-1;
            if( matrix[i][end] < target ){
                continue;
            }
            while( start <= end ){
                int mid = start + (end - start)/2;
                if( matrix[i][mid] > target ){
                    end = mid - 1;
                }
                else if( matrix[i][mid] < target ){
                    start = mid + 1;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};
