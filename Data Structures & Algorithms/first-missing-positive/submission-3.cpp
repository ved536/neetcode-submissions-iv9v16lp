class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>ans(nums.size()+1,0);
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= nums.size()){
                ans[nums[i]] = nums[i];
            }
        }
        int i;
        for (i = 1; i <= nums.size(); i++){
            if (ans[i] == 0){
                return i;
            }
        }
        return nums.size()+1;
    }
};