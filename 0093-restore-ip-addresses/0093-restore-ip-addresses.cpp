class Solution {
public:
    vector<string>res;
    void rec(string &s,int i,int d,string curr){
        if(d==5){
            if(i!=s.size())
                return;
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        
        if(s[i]=='0'){
            rec(s,i+1,d+1,curr+s[i]+'.');
            return;
        }
        
        string purr="";
        for(int j=0;j<3 && i+j<s.size();j++){
            purr+=s[i+j];
            if(stoi(purr)<256)
                rec(s,i+j+1,d+1,curr+purr+'.');
            else
                return;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        rec(s,0,1,"");
        return res;
    }
};