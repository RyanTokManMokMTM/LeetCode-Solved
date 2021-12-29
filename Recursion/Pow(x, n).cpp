class Solution {
public:
    double myPow(double x, int n) {
        //let change n to abs first
        // a question here
        // why even power is x*x and next power is n/2?
        // why odd power is preRes * x^n-1?
        //beacuse 2^10 = 1024 and 4^5 = 1024
        if(n == 0)return 1.0;
        
        if(n%2==0){
            return myPow(x*x,n/2);
        }
        
        if(n > 0){
            return x*myPow(x,n-1);
        }else{
            return (1/x)*myPow(x,n+1);
        }
    }
};