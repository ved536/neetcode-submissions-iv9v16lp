class Solution {
private:
    stack<int>main;
    int reqNum;
public:
    int evalRPN(vector<string>& tokens) {
        for(string& token : tokens){
            if(token == "+"){
                int second = main.top();
                main.pop();
                int first = main.top();
                main.pop();
                main.push(first+second);
            }
            else if(token == "-"){
                int second = main.top();
                main.pop();
                int first = main.top();
                main.pop();
                main.push(first-second);
            }
            else if(token == "*"){
                int second = main.top();
                main.pop();
                int first = main.top();
                main.pop();
                main.push(first*second);
            }    
            else if(token == "/"){
                int second = main.top();
                main.pop();
                int first = main.top();
                main.pop();
                main.push(first/second);
            }
            else{
                main.push(stoi(token));
            }
        }
        return main.top();
    }
};
