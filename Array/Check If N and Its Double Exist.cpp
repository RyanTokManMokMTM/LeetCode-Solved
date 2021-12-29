class Solution {
public:
    unordered_map<int,int> hash;
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0;i<arr.size();i++){
            for(int j = i+1;j<arr.size();j++){
                if(arr[i] == arr[j]*2 || (arr[i] == arr[j]/2 && arr[j]%2 == 0)) return true;
            }
        }
        return false;
    }
};