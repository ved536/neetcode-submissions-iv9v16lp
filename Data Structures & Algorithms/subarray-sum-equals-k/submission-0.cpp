class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> m;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if ( currSum == k){
                count++;
            }
            int val = (currSum - k);
            if (m.find(val) != m.end()){
                count += m[val];
            }
            if (m.find(currSum) == m.end()){
                m[currSum] = 0;
            }
            m[currSum]++;
            
        }
        return count;
    }
};