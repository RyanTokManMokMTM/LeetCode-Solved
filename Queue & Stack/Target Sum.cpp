class Solution {
public:
    int count = 0;
    int total;
    int findTargetSumWays(vector<int>& nums, int target) {
        //coz recursive function -> redundant function -> same procedure will calculate again
        //try to memorize the result that has calculted
        //-> our target won't greater than our list'snum
        
        total = accumulate(nums.begin(),nums.end(),0);// get the sum of current list
        //suppose 5's 1 = 1+1+1+1+1 = 5
        
        //decalar an 2d array to memorize the value
        //1d -> the length of the list
        //the result may be a nagative number -> 2d size -> total(-) + total + 1
        //if nagaitive result + total -> will convert to positive
        int size = nums.size();
        int **mem = new int*[size];
        for(int i = 0;i<size;i++){
            mem[i] = new int[total * 2 + 1];
            for(int j = 0;j<total * 2 + 1;j++) mem[i][j] = INT_MIN;
        }
        return calculate(nums,target,0,0,mem);
    }
    
    //for each index -> [1,1,1,1,1]
    //in each index will do an adding and subtracting adding->result + subtracting-> result => mean current index of [sum+target] of total expression that can be built
    //suppose index 4 and sum + target is 10 [5][9] -> has 1 expression 1+1+1+1+1-1 = 3 add(0)+substract(1) = 1
    //set [5][9] 1+1+1+1 + target = 9,at sum in 9 do an add and subtract [5][9] = 1
    //next next rount is 1+1+1 - 1(substrack part of 1+1+1) 
    //in 1+1+1-1 case => 1+1+1-1+1 this [5][9] = 1,return 1 ->add = 1 and strack = 1 so case 1+1+1 [2][8] = 2...
    //etc
    int calculate(vector<int>& nums, int target,int sum,int index,int** mem){
        if(index == nums.size()){
            if(sum == target){
                return 1; 
            }else{
                return 0;
            }
        }else{
            if(mem[index][sum + total] != INT_MIN){ // ture -> the result is calculated
                return mem[index][sum + total]; //return the mem result
            }
           //add procedure
            int add = calculate(nums,target,sum+nums[index],index+1,mem); //0
            //subtract procedure
            int subtract = calculate(nums,target,sum-nums[index],index+1,mem);//0
            //add + subtrack
            mem[index][sum+total] = add + subtract;
            return mem[index][sum+total];
        }
    }
    
    
};