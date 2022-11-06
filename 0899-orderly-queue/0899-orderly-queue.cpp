class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        
        string res=s;
        for(int i=0;i<s.size()-1;i++){
            s.push_back(s[0]);
            s.erase(s.begin());
            res=min(res,s);
        }
        
        return res;
    }
};