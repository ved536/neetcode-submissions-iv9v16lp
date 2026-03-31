class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    int freq = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++){
        if (freq == 0){
            ans = nums[i];
        }
        if (ans == nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    if ( freq > 1 )
    return true;
    else
    return false;
    }
};