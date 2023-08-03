class Solution {
public:
    vector<string> map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void rec(int i,int n,string digit,string& curr,vector<string>&res){
        if(i==n){
            res.push_back(curr);
            return;
        }
        
        int m=digit[i]-'0'-2;
        
        for(int j=0;j<map[m].size();j++){
            curr.push_back(map[m][j]);
            rec(i+1,n,digit,curr,res);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string curr;
        
        if(digits.size())
            rec(0,digits.size(),digits,curr,res);
        
        return res;
    }
};