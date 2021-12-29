class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visted(n+1,false);
        q.push(n); //add value n to queueu
        visted[n] = true; //value n is already added to queue
        int count = 0;// to count each level
        
        //for each level will generate its a value that current value minus by `a` prefer square
        //for each `a` will generate other `a` that minus by a prefer square
        //until `a` - prefer square = 0 ->that mean the current value `n` is reached the prefect Squeares
        
        //loop over the queue
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int current = q.front();q.pop();
                if(current == 0) return count;
                for(int j = 1;current - j*j >= 0;j++){
                    if(!visted[current - j*j]){
                        q.push(current -j*j); //push the value
                        visted[current - j*j] = true;
                    }
                }
            }
            count ++;
        }
        return count;
    }
};
//try to use bfs instead of dp