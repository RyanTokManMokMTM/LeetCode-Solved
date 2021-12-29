class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       //check arr first
        if(arr.size() == 0 || arr.size() < 3) return false;
        if(arr[0] > arr[1]) return false;
        bool increaing = true; //first thing must be increasing
        
        //O(N)
        for(int i = 1;i<arr.size();i++){
            //check pre and current is equal
            if(arr[i-1] == arr[i]) return false;
            if(increaing){
                //current is increasing state
                if(arr[i-1] > arr[i]) increaing = false;
            }
            else{
                if(arr[i-1] < arr[i]) return false;
            }
        }
        return !increaing;
    }
};