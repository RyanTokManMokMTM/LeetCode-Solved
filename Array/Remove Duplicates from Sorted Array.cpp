class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int pre = -999;
        for(int i = 0;i<nums.size();i++){
            /*
            Condition: current is -999 set to current value
            Condition: current is equal set current value to -999
            Condition: not equal set to current value
            */
            if(pre == -999){
                pre = nums[i];
            }
            else{
                if(pre == nums[i]){
                    nums[i] = -999;
                }else{
                    pre = nums[i];
                }
            }
        }
        
        int a=0,b=0,s=0;
        while(b<nums.size()){
            if(nums[b] != -999){
                nums[a++] = nums[b++];
                ++s;
            }else{
                ++b;
            }
        }
        return s;
    }
};