class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //calculating the power
        vector<int> result(nums.size(),0);
        int i  = 0,j = nums.size()-1,k=nums.size()-1;
        
        //We need to calculate each i and j in the vector
        //Time O(N)
        //Space O(N)
        //compare with i(front) and j(back) which square is larger,then put it at the end of the resoult
        while(i<=j){
            if(abs(nums[i]) > abs(nums[j])){
                result[k--] = nums[i] * nums[i];
                i++;
            }else{
                result[k--] = nums[j]*nums[j];
                j--;
            }

        }
        return result;
    }
};