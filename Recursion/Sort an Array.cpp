class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //try to use merge sort
        if(nums.size() == 0){
            return nums;
        }
        return devide(nums);
    }
    
    //try to use 
    vector<int> devide(vector<int> nums){
        if(nums.size() == 1){
            //the list is only 1 ele
            return nums;
        }
        
        //calculate the mid point
        int mid = nums.size() / 2;
        //get the left list
        vector<int> l(nums.begin(),nums.begin() + mid);
        vector<int> r(nums.begin()+ mid,nums.end());
        
        
        vector<int> left = devide(l); //mid -1
        vector<int> right = devide(r); //mid
        
        //after received the left list and right list
        //compare 2 list and marge
        vector<int> result;
        merge(result,left,right);
        
        return result;
    }
    
    void merge(vector<int>& res,vector<int> left,vector<int> right){
        //compare 2 list and add to resulti
        int i = 0,j = 0;
        while(i < left.size() && j < right.size()){
            //either one is false ,break
            //3 cases here: 1.i and j have same size 2.i < j 3 i > j
            if(left[i] <= right[j]){
                res.push_back(left[i++]); //push 
            }else {
                res.push_back(right[j++]); //push 
            }
        }
        
        //here add the remain ele to list
        for(int l = i;l<left.size();l++)
            res.push_back(left[l]); //push remainding left elements
        for(int r = j;r<right.size();r++)
            res.push_back(right[r]);//push remainding right elements
        
    }
};