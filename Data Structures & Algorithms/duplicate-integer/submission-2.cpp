class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int freq = 1, ans = nums[0];
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == nums[i-1]){
            freq++;
        }else{
            freq = 1;
            ans = nums[i];
        }
        if ( freq > 1 ){
        return true;
        }
    }
    return false;
    }
};