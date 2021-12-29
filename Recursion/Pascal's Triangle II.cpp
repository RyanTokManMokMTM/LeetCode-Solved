class Solution {
public:
    vector<int> result;
    vector<int> getRow(int rowIndex) {
        result.push_back(1);
        if(rowIndex == 0)
            return result;
        generate(rowIndex,1);//we start at row 1
        return result;
    }
    
    void generate(int row,int cur){
        if(cur > row) return; //is end of
        int newTotal = (cur++)+1; //current array size is rowIndx+1,suppose is 0th row
        int oldSize = result.size();
        
        vector<int> temp;
        temp.reserve(newTotal);
            
        temp.insert(temp.begin(),result[0]); //reuslt first ele store to temp first
        temp.insert(temp.end(),result[result.size()-1]); //reuslt last ele store to temp 
        
        if(temp.size() == temp.capacity()){ //if full now
            //next term
            //and store to result 
            result.resize(newTotal);
            result.assign(temp.begin(),temp.end());
        }else{
            //genera the number
            for(int i = 1;i<oldSize;i++){
                int val = result[i]+result[i-1];
                temp.insert(temp.begin()+i,val);
            }
            result.resize(newTotal);
            result.assign(temp.begin(),temp.end());
        }
        //check current size is equal to capacity
        generate(row,cur);
        
    }
    

};