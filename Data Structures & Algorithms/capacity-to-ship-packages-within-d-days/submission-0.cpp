class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        for( int weight : weights ){
            maxi = max(maxi , weight);
        }
        int start = maxi;
        int end = maxi*weights.size();
        int ans = end;
        while( start <= end ){
            int total = 1;
            int mid = start + (end-start)/2;
            int sum = 0;
            for(int w : weights){
                if( sum + w > mid ){
                    total++;
                    sum = w;
                }
                else {
                    sum += w;
                }
            }
            if( total > days ){
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