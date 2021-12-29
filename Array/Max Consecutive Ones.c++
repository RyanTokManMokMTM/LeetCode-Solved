class Solution {
public:

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0,one = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) one = 0;
            if(nums[i] == 1) one++;
            counter = max(counter,one);
        }
        
        return  counter;
    }
};