class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0; int n = nums.size(); int ans = nums[0];
        sort(nums.begin(),nums.end());
        for ( int i = 0; i < n; i++ ){
            if ( nums[i] == ans ){
                freq++;
            }
            else{
                freq = 1;
                ans = nums[i];
            }
            
            if( freq > n/2){
                return ans;
            }
            
            
            
            
        }





    }
};