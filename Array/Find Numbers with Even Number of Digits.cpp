class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(int i = 0;i<nums.size();i++){
            int temp = nums[i];
            int tempTime = 0;
            for(int temp = nums[i];temp > 0;temp /= 10) tempTime++;
            if(tempTime%2 == 0) counter++;
        }
        return counter;
    }
};