class Solution {
public:
    int thirdMax(vector<int>& nums){
        int n = nums.size();//get the size
        sort(nums.begin(),nums.end());//asc
        
        if(n < 3){
            //last than 3 ele in array
            return nums[n-1];
        }
        
        //the last one always the max,ignore that
        int counter = 1;// counter the third maxinums value
        for(int i = n-2;i>=0;i--){
            if(nums[i+1] != nums[i])
                counter++;
            if(counter == 3)
                return nums[i]; // the third max is now found
        }
        return nums[n-1];
    }
};