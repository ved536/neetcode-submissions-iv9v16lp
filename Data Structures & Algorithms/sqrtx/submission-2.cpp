class Solution {
public:
    int mySqrt(int x) {
        int ans;
        int start = 1;
        int end = start + (x-start)/2;
        if( x == 0){
            return 0;
        }
        while( start <= end ){
            int mid = start + (end - start)/2;
            if( mid > x/mid){
                end = mid - 1;
            }
            else if( x/mid > mid ){
                ans = mid;
                start = mid + 1;
            }
            else{
                return mid;
            }
        }
        return ans;
    }
};