class Solution {
public:
    bool isAlpha(char c){
        if ((tolower(c) >= '0' && tolower(c) <= '9') || 
        (tolower(c) >= 'a' && tolower(c) <= 'z'))
            return true;
        return false;
    }
    bool isPalin(string& s, int l, int r){
        while ( l <= r){
            if ( !isAlpha(s[l]) ) {
                l++; 
            }
            else if ( !isAlpha(s[r]) )
                r--; 
            else if ( tolower(s[l]) != tolower(s[r]) )
                return false;
            else{

            l++;
            r--;
        }
        }
        return true;        
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while( i <= j){
            if (isAlpha(s[i])==false){
                i++;
            }
            else if (isAlpha(s[j])==false){
                j--;
            }
            else if (tolower(s[i]) != tolower(s[j])){
                return (isPalin(s, i+1, j) || isPalin(s, i, j-1));
            }
            else{
                i++;
                j--;
            }
        }      
        return true;
    }
};