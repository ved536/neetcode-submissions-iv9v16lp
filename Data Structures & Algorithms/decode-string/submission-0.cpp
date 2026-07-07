class Solution {
public:
    string decodeString(string s) {
        stack<int>num;
        stack<string>ch;
        int count = 0;
        for( char letter : s ){
            if( isdigit(letter) ){
                count = count*10 + (letter-'0');
            }
            else if( letter == '['){
                num.push(count);
                ch.push("[");
                count = 0;
            }
            else if( letter != ']' ){
                ch.push(string(1,letter));
            }
            else{
                count = 0;
                string req = "";
                while(ch.top() != "["){
                    req = ch.top() + req;
                    ch.pop();
                }
                ch.pop();
                int mult = num.top();
                num.pop();
                string reqsub = "";
                for(int i = 0; i < mult; i++){
                    reqsub += req;
                }
                ch.push(reqsub);
            }
        }     
        string result = "";
        while( !ch.empty() ){
            result = ch.top() + result;
            ch.pop();
        }
        return result;
    }
};