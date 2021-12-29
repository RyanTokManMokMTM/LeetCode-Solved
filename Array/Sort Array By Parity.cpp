class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //Space O(3N)
        //Time O(N)
        vector<int> odd;
        vector<int> even;
        for(auto i : nums){
            if((i&1) == 0){ //not odd
                even.push_back(i);
            }
            if((i&1) == 1){ //not odd
                odd.push_back(i);
            }
        }
        
        //now we had odd and even array
        //push odd array to the back of even
        even.insert(even.end(),odd.begin(),odd.end());
        return even;
            
    }
};