class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m!=n){
            return false;
        }
        else { 
        int count[26]= {0};
        for (int i = 0; i < m ; i++){
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++){
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if ( count[i] != 0){
                return false;
            }
        
        }
        
        }
        return true;
    }
};
