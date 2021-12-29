class Solution {
public:
    int heightChecker(vector<int>& heights) {
        //max number is 100
        //calculate all heights in the list
        vector<int> counter(101);
        for(auto i : heights) counter[i] ++;
        
        int ans = 0,i = 1,currentHeight = 0;
        while(currentHeight < heights.size()){
            if(counter[i]){ //counter is not empty
                if(i != heights[currentHeight]) //current number is not same as current i
                    ans++;
                
                counter[i]--;
                currentHeight++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};