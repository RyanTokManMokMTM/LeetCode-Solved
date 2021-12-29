class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //just using an array to recore the lock and vistied node
        bool visited[10000] = {false};
        for(auto lock : deadends)
            visited[stoi(lock)] = true;
        
        if(visited[0])
            return -1;
        
        int value = stoi(target); //change target to int
        int dest = 0; //total step
        
        //using a vector to instead queue;
        //O(N*1) = O(N) time
        //space : O(N) bool, O(N) int vector
        vector<int> queue = {0};// start at "0000"
        while(!queue.empty()){ 
            vector<int> temp;// for storing current node and init O(<N)
            //for each value in temp
            for(int current : queue){ //if there is no look, it need loop over 0-9999 -> O(N)
                if(current == value) return dest;
                
                //O(4) + O(2) = O(6) => O(1)
                for(int pow = 1;pow<10000;pow*=10){ //pow used to get each digitals(total 4 digitals)
                    //current digital
                    auto dig = current/pow % 10; //1234 / 10 % 10 = 123.4 = 3.4 = 3
                    
                    //for each dig need to +1 and -1;
                    for(int t = -1;t<2;t+=2){ //value - 1 and next -1+2 = 1 -> value +1
                        //formuler
                        //current value - current digital * pow + (dig+t+10(for 0-1 case)) %10 * pow
                        //example:
                        //  assume pow is 10 ,1234,dig=3,1234-3*10+(3-1+10)%10 * 10
                        //  ans = 1234 - 30 + (2+10)%10 * 10 = 1204 + (12)%10*10 = 1204+2*10 = 1224
                        //  assume pow is 10 ,1234,dig=3,1234-3*10+(3+1+10)%10 * 10
                        //  ans = 1234 - 30 + (4+10)%10 * 10 = 1204 + (14)%10*10 = 1204+4*10 = 1244
                        auto newVal = current - dig * pow + (dig + t + 10) % 10 *pow;
                        
                        //check is lock or visited value
                        if(!visited[newVal]){
                            //add to our list
                            temp.push_back(newVal);
                            visited[newVal] = true; //now is visted(bsf node)
                        }
                    }
                    
                }
            }
            dest++;// one step futher
            //need to swap temp and our queue
            printf("%d ",temp.size());
            swap(queue,temp);
    
        }
        
        //not found 
        return -1;
    }
};