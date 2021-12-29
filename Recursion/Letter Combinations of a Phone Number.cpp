class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        //create the map for getting alphabats
        if(digits.size() == 0) return res;
        
        map<char,string> phone;
        phone.insert(pair<char,string>('2',"abc"));
        phone.insert(pair<char,string>('3',"def"));
        phone.insert(pair<char,string>('4',"ghi"));
        phone.insert(pair<char,string>('5',"jkl"));
        phone.insert(pair<char,string>('6',"mno"));
        phone.insert(pair<char,string>('7',"pqrs"));
        phone.insert(pair<char,string>('8',"tuv"));
        phone.insert(pair<char,string>('9',"wxyz"));
        
        vector<string> alphabets;
        for(int i = 0;i<digits.size();i++){
            auto chars = phone.find(digits[i]);
            alphabets.push_back(chars->second);
        }
        
        string current = "";
        
        phoneCharsCombinations(alphabets,current,0,alphabets.size()); //ignore the last one
        return res;
    }
    
    void phoneCharsCombinations(vector<string>& allchars, string& temp, int front,int size){
        if(temp.size() == size){
            res.push_back(temp); //if there are 3 number ,total string length is 3
            return;
        }
        //loop over the list
        for(int i = 0;i<allchars[front].size();i++){
            temp.push_back(allchars[front][i]);//push it to the string -> condindate string
            //sub candindate
            phoneCharsCombinations(allchars,temp,front+1,size);
            //pop back the string
            temp.pop_back();
        }

    }
};