class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>ans(26,0);
        for(int i = 0; i < s1.size(); i++){
            ans[s1[i]-'a']++;
        }
        for(int i = 0; i < s2.size();i++){
            int j = i;
            int windIndex = 0;
            vector<int>windowfreq(26,0);
            while(windIndex < s1.size() && j < s2.size()){
                windowfreq[s2[j]-'a']++;
                j++;
                windIndex++;
            }
            if (windowfreq == ans){
                return true;
            }
        }
        return false;
    }
};
