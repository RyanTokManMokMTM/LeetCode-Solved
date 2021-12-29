class Solution {
public:
    /*
        example:
        r1 : 0
        r2 : 0 1
        r3 : 0 1 1 0
        r4 : 0 1 1 0 1 0 1
        k = 6,n = 4
        
        1. mid = 2^3/2 = 4 ;k > 4, k-4=2 return 0(reverse,second part)
        2. mid = 2^2/2 = 2 ;k<=2 ,k reutn 1 (first part)
        3. mid = 2^1 =2/1 ;k>1 ,k-1 = 1 reutrn 1 (reverse,second part)
        4. return 0 (n is now 0 and k i now 0)
    */
    int kthGrammar(int n, int k) {
        //ignore the replacement
        //the first one will be 0
        if(n == 1 && k == 1) return 0;
        
        //now calculate the mid
        //check the k is belonged to which part of value
        int mid = pow(2,n-1)/2;
        
        // k <= mid => k is belonged to the first part(n row part)
        if(k <= mid){
            //here will always is the first part
            return kthGrammar(n-1,k);
        }else{
            //here will always is the second part
            return !kthGrammar(n-1,k-mid); //why k - mid. Beacuse of next round  k is belonged to first part
        }

    }
};