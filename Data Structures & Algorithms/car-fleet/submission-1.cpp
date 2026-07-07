class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
       vector<pair<int,double>>ans(n);
       for(int i = 0; i < n; i++){
            double time = (double)(target - position[i])/speed[i];
            ans[i] = {position[i],time};
       } 
       sort(ans.begin(),ans.end());
       stack<double>timee;
       for(int i = 0; i < n; i++){
            double currtime = ans[i].second;
            while( !timee.empty() && currtime >= timee.top() ){
                timee.pop();
            }
            timee.push(currtime);
        } 
        return timee.size();
    }
};
