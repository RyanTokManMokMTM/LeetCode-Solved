class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        //O(N)
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != val){
                //movie i value to cur
                // cur is for removed index
                nums[cur] = nums[i];
                cur++;
            }
        }
        return cur;
    }
};