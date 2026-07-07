class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string>ans;
        while(getline(ss,token,'/')){
            if(token == "" || token == "."){
                continue;
            }
            if(token == ".."){
                if( !ans.empty() ){
                    ans.pop();
                }
            }
            else{
                ans.push(token);
            }
        }
        string result = "";
        while( !ans.empty() ){
            result = '/' + ans.top() + result;
            ans.pop();
        }
        if(result == ""){
            return("/");
        }
        else{
            return result;
        }
    }
};