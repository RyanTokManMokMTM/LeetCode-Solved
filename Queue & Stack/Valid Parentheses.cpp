class Solution {
public:
    bool isValid(string s) {
        //try to use a stack
        stack<char> bracketStack;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                // add it to the stack if it's a open  bracket
                bracketStack.push(s[i]);
            }else{
                //if current is not  , compare to the stack top
                //if both bracket are match, then pop and continues
                //other case is that : ()))))) -> the statck will only have 1 value
                if(!bracketStack.empty() && isVaild(bracketStack.top(),s[i])){
                    bracketStack.pop();
                }else{
                    return false;
                }
            }
        }
        return bracketStack.empty(); //all elements in the stack is matching -> true,
        //if still remain elements ->same open bracket not match yet
    }
    
    bool isVaild(char open,char close){
        //either one is ture => true else false
        return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}') ;
    }
};