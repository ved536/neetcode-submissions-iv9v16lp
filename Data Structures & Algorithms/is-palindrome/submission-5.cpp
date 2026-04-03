class Solution
{
public:
    bool isAlpha(char c){
            if ((tolower(c) >= '0' && tolower(c) <= '9') || 
            (tolower(c) >= 'a' && tolower(c) <= 'z'))
                return true;
            return false;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while ( i <= j){
            if ( !isAlpha(s[i]) ) {
                i++; 
            }
            else if ( !isAlpha(s[j]) )
                j--; 
            else if ( tolower(s[i]) != tolower(s[j]) )
                return false;
            else{

            i++;
            j--;
        }
        }
        return true;
        }
    
};
