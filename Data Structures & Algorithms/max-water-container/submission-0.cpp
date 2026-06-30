class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int currAmount; int maxAmount = 0;
        while (i < j){
            if (heights[i] < heights[j]){
                currAmount = heights[i]*(j-i);
                maxAmount = max(maxAmount,currAmount);
                i++;
            }
            else{
                currAmount = heights[j]*(j-i);
                maxAmount = max(maxAmount,currAmount);
                j--;
            }
        }
        return maxAmount;
    }
};
