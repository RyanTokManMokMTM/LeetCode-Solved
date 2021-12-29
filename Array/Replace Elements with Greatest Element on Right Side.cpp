class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size() == 0) return arr;
        int maxNum = -1;
        for(int i = arr.size()-1;i>=0;i--){
            int tempCurrent = arr[i];
            arr[i] = maxNum;
            maxNum = max(maxNum,tempCurrent);
        }
        return arr;
    }
};