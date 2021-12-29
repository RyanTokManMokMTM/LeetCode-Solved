class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        //from 1 - n combine 1 to k
        vector<int> nums;
        combineCandinadate(nums,1,n,k);
        return res;
        
    }
    
    void combineCandinadate(vector<int>& nums,int index,int n,int total){
        if(total==0){ //no need to combine any number
            res.push_back(nums); //total k to combine with
            return;
        }
        
        //here just need to combine the number of n-k
        //for example : n = 4(total 1-4) and k=2(combine 2 number)
        //the first number is i to 4-2+1 = 1->3 3number only ,the last number will repeat the previous 
        //like 4,1 4,2 4,3 etc
        //the second = i+1 to 4-(k-1)+1 = 2 to 4 1,2 1,3 1,4
        for(int i = index;i<=n-total+1;i++){
            //(O(x+n))
            //backtracking algorithmn            
            nums.push_back(i);
            combineCandinadate(nums,i+1,n,total-1);
            nums.pop_back();
        }
        
    }
};