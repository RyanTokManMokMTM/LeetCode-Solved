class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> dayRecord(n,0);//all set to 0;
        stack<int> day;
        
        //need O(N^2 -> for N and While N) and O(2N) Space
        for(int i = 0;i<n;i++){
            //need to compare all value in the stack
            while(!day.empty()){
                //if no empty check current value i and the top value
                int preIndex = day.top(); 
                if(temperatures[i] <= temperatures[preIndex])
                    break; //go to another iterator, one step further
                
                //pop and get the day
                dayRecord[preIndex] = i - preIndex;
                day.pop();
            }
            day.push(i);// push current i and wait to calucate the date
        }
        return dayRecord;
    }
};