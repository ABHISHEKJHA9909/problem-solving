class Solution {
public:
    bool check(string s,string t){
        int n=s.size(); //length of string ;
        unordered_map<char,char>m1; //s---->t
        unordered_map<char,char>m2; //t---->s
        
        for(int i=0;i<n;++i){
            char c1=s[i];
            char c2=t[i];
            
            
            if((m1[c1] && m1[c1]!=c2)||(m2[c2] && m2[c2]!=c1))
                return false;
                
            m1[c1]=c2;
            m2[c2]=c1;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for(string &s:words){
            if(check(s,pattern)==true)
                res.push_back(s);
        }
        
        return res;
    }
};