class Solution {
private:
    vector<int>final;
    stack<int>ans;
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for(int& aster : asteroids){
            bool destroyed = false;
            while( !ans.empty() && aster < 0 && ans.top() > 0){
                if( -(aster) > ans.top() ){
                    ans.pop();
                }
                else if( -(aster) == ans.top() ){
                    ans.pop();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                ans.push(aster);
            }
        }
        int n = ans.size();
        for( int i = 0; i < n; i++){
            final.insert(final.begin(),ans.top());
            ans.pop();
        }
        return final;
    }
};