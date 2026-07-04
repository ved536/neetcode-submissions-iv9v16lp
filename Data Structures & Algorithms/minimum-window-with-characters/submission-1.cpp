class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>reqWindow(256,0);
        for(int i = 0; i < t.size(); i++){
            reqWindow[t[i]]++;
        }
        vector<int>currWindow(256,0);
        int formed = 0;
        int required = t.size();
        int i = 0;
        int startIndex = -1;
        int minNum = INT_MAX;
        for(int j = 0; j < s.size(); j++){
            currWindow[s[j]]++;
            if(reqWindow[s[j]] > 0 && currWindow[s[j]] <= reqWindow[s[j]]){
                formed++;
            }
            while(formed == required){
                if(j-i+1 < minNum){
                    minNum = j-i+1;
                    startIndex = i;
                }
                currWindow[s[i]]--;
                if(reqWindow[s[i]] > 0 && currWindow[s[i]] < reqWindow[s[i]]){
                    formed--;
                }
                i++;
            }
        
        }
        return(startIndex == -1) ? "" : s.substr(startIndex,minNum);
    }
};
