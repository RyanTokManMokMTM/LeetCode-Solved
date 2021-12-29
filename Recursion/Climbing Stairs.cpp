class Solution {
public:
    int result[46] = {0};
    int climbStairs(int n) {
        //using fib solution with recurrive
        if(n==1) { //set = 1 => fib(1) = 1
            result[n] = 1;
            return 1;
        }else if (n== 2){ //set fib(2) = 2 ->fib(1)+fib(0) = 2
            result[n] = 2;
            return 2;
        }else if(result[n]!=0)
            return result[n]; //just return a stored n result
        
        result[n] = climbStairs(n-1)+climbStairs(n-2); //recurrsive
        return result[n]; //return the result
    }
};