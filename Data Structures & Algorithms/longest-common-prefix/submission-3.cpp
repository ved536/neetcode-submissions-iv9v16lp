class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size()-1];
        int i = 0;
        while( i < str1.length()){
            if (str1[i] == str2[i]){
                i++;
                
            }
            else{
                break;
            }
        }
        if (i == 0){
            return"";
        }
        else return str1.substr(0,i);
        
    }

};