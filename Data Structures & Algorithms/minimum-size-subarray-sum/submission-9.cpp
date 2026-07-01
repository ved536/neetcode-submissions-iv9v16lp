class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int min_num = INT_MAX;
        int currsum = 0;
        for (int right = 0; right < n; right++){
            currsum += nums[right];
            while(currsum >= target){
                min_num = min(min_num,right-left+1);
                currsum -= nums[left];
                left++;
            }
        }
        return(min_num == INT_MAX)? 0 : min_num;
    }
};