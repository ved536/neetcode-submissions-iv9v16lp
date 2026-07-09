class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for( int pile : piles ){
            maxi = max(maxi,pile);
        }
        int start = 1;
        int end = maxi;
        int ans = end;
        while( start <= end){
            int mid = start + (end-start)/2;
            int time = 0;
            for( int pile : piles ){
                time += (pile+mid-1)/mid;
            }
            if( time > h ){
                start = mid + 1;
            }
            else{
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};
