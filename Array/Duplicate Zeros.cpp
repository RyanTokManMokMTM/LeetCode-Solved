class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> copyArr(arr.size());
        int pos = 0;
        //Time O(N)
        //Space O(2N) = O(N)
        for(auto ele : arr){
            copyArr[pos] = ele; //copy currentEle first
            if(++pos == arr.size()) break; //the check next pos is end of array
            
            if(ele == 0){ //next pos is not the end,then check current value is zero
                copyArr[pos] = ele; //copy current value again
                if(++pos == arr.size()) break; //check next post is the end
            }
        }
        
        //O(N)?
        copy(copyArr.begin(),copyArr.end(),arr.begin()); // copy copy array to original array
    }
};