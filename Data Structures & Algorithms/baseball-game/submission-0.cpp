class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>ans;
        for(const string &op : operations){
            if(op == "+"){
                int no1 = ans.top();
                ans.pop();
                int no2 = ans.top();
                int reqsum = no1 + no2;
                ans.push(no1);
                ans.push(reqsum);
            }
            else if(op == "D"){
                ans.push(ans.top()*2);
            }
            else if(op == "C"){
                ans.pop();
            }
            else{
                ans.push(stoi(op));
            }
        }
        int sum = 0;
        while(!ans.empty()){
            sum += ans.top();
            ans.pop();
        }
        return sum;
    }
};