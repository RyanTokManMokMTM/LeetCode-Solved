class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        findParenthesis(v,"",0,0,n);
        return v;
    }
    
    void findParenthesis(vector<string> &v, string current,int open,int close,int max){
        //basic case
        if(current.size() == max * 2){ // max for open max for close = 2Max
            v.push_back(current);
            return;
        }
        
        //recusion
        //open curly braces
        if(open < max){ //open curly braces can not geater than max value(n)
            findParenthesis(v,current+"(",open+1,close,max); //add a open curly braces to then string
        }
        
        //if close is greater than open -> mean something wrong
        //case : )( is not what quesion wanted
        if(close < open){ //for the close curly braces case
            findParenthesis(v,current+")",open,close+1,max);
        }
        return;
        // close curly braces
    }
};