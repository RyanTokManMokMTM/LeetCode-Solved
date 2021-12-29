class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //still O(2N)
        //Denote all element in the nums is the index -1 in the array
        //Loop over the array and visis the index , if index is not visted yet *=-1
        //after that loop with its index i and check which one is not <0 then append to array with(index i+1)
        
        int n = nums.size();
        vector<int> r;
        for(auto &ele : nums){
            //suppose ele is -4(visted),nums[abs(4)-1] nums[3] => number of 3 is visted?
            if(nums[abs(ele)-1] > 0) 
                nums[abs(ele)-1] *= -1; //if not visited set to num*-1
        }
        
        for(int i = 0;i<nums.size();i++)
            if(nums[i] > 0) r.push_back(i+1);
        
        return r;
    }
};