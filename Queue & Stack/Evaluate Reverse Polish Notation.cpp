class Solution {
public:

    int doOperation(const string str,int a,int b){
        if(str == "+"){
            return a + b;
        }else if(str == "-"){
            return a - b;
        }else if(str == "*"){
            return a * b;
        }else {
            return a / b;
        }
    }
    
    int evalRPN(vector<string>& tokens) {
        /*
        strategy: Using a stack /  array to store the number
        //if current tokens is not a number,is an opretor pop up 2 number from a stack ,after operation,put it back and continues;
        */
        
        stack<int> value;
        for(string token : tokens){
            if(token == "+"){
                int valueA = value.top();value.pop();
                int valueB = value.top();value.pop();
                
                value.push(valueB + valueA);
            }else if(token == "-"){
                int valueA = value.top();value.pop();
                int valueB = value.top();value.pop();
                 
                value.push(valueB - valueA);
                
            }else if(token == "*"){
                int valueA = value.top();value.pop();
                int valueB = value.top();value.pop();
                
                 value.push(valueB * valueA);
            }else if(token == "/"){
                int valueA = value.top();value.pop();
                int valueB = value.top();value.pop();
                
                value.push(valueB / valueA);
            }else{
                value.push(stoi(token));
            }
        
        }
        
        return value.top();
    }
    
};