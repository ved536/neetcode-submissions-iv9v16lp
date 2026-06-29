class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i, k, j, l=0;
        for(i = 0;i < nums.size();i++){
            if ( i > 0 && nums[i] == nums[i-1]){
                    continue;
                }
            int j = i+1, k = nums.size()-1;
            while (j < k){
                if ( i == j){
                    j++;
                }
                else if ( i == k){
                    k--;
                }
                else if ( nums[i] + nums[j] +nums[k] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    l++;
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else if(nums[i] + nums[j] +nums[k] < 0){
                    j++;
                }
                else if(nums[i] + nums[j] +nums[k] > 0){
                    k--;
                }
            }
        }
        return ans;
    }
};
