class Solution {
public:
    bool isValid(string s) {
        stack<char>ans;
        for(char c : s){
            if(c == '('){
                ans.push(')');
            }
            else if(c == '{'){
                ans.push('}');
            }
            else if(c == '['){
                ans.push(']');
            }
            else{
                if(ans.empty() || c != ans.top()){
                    return false;
                }
                ans.pop();
            }
        }
        return ans.empty();
    }
};
