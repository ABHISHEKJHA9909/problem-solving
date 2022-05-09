class Solution {
public:
    vector<string>m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    
    void rec(string num,int i,string s){
        if(i<num.size()){
            int curr=num[i]-'0';
            for(char &c: m[curr]){
                s.push_back(c);
                rec(num,i+1,s);
                s.pop_back();
            }
        }
        else{
            if(s!="")
                res.push_back(s);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        rec(digits,0,"");
        return res;
    }
};