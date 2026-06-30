class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_set<int>ans;
        int i = 0, j = 0;
        while(j < s.size()){
            if(ans.find(s[j])== ans.end()){
                ans.insert(s[j]);
                maxLength = max(maxLength,(int)ans.size());
                j++;    
            }
            else{
                ans.erase(s[i]);
                i++;
            }
        }
        return maxLength;
    }
};
