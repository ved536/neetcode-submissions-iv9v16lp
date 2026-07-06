class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>final(temperatures.size(),0);
        stack<int>ans;
        for(int i = 0; i < temperatures.size(); i++){
            while( !ans.empty() && temperatures[i] > temperatures[ans.top()] ){
                int index = ans.top();
                ans.pop();
                final[index] = i-index;
            }
            ans.push(i);
        }
        return final;
    }
};
