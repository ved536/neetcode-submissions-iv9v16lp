class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>charCount(26,0);
        int maxFrequency = 0;
        int maxWindow = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++){
            charCount[s[j]-'A']++;
            maxFrequency = max(maxFrequency, charCount[s[j]-'A']);
            while((j-i+1)-maxFrequency > k){
                charCount[s[i]-'A']--;
                i++;
            }
            maxWindow = max(maxWindow,j-i+1);
        }
        return maxWindow;
    }
};

    
    
    
    