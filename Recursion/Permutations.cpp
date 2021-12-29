class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        generator(nums,0,nums.size());
        return result;
    }
    
    void generator(vector<int>& nums,int index,int n){
        if(index == nums.size()){
            //this for basic case
            //current list is equal to the maxinums number of the given list
            //push and return
            result.push_back(nums);
            return;
        }
        
        //still backtracking
        //but we going to use swap rather than append to another list
        for(int i = index;i<n;i++){
            //going to swap curret idx and i;
            swap(nums[i],nums[index]); // sawp the value suppose 1 - 2 -3 and index =0 i = 2-1-3 when backtracking to the top level;
            //go into the candindate
            generator(nums,index+1,n);
            
            //reset the state
             swap(nums[i],nums[index]); // swap back to the previous state/order
        }
    }
};