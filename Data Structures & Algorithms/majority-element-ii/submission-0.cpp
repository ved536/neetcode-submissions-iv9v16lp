class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = 0;
        int second = 1;
        int count1=0;
        int count2=0;
        for (int num : nums){
            if (num == first){
                count1++;
            }
            else if (num == second){
                count2++;
            }
            else if (count1 == 0){
                first = num;
                count1 = 1;
            }
            else if (count2 == 0){
                second = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1=count2=0;
        vector<int>res;
        for (int num : nums){
            if (num == first){
                count1++;
            }
            if(num == second){
                count2++;
            }
        }
        if (count1 > nums.size()/3){
            res.push_back(first);
        }
        if (count2 > nums.size()/3){
            res.push_back(second);
        }
        return res;  

    }
};