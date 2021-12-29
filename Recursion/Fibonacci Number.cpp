class Solution {
public:
    int fib(int n){
        vector<int> fib(n+1);
        for(int i = 1;i<n+1;i++){
            if(i==1){
                fib[i] = 1;
            }else{
                fib[i] = fib[i-1]+fib[i-2];
            }
        }
        return fib[n];
    }
};