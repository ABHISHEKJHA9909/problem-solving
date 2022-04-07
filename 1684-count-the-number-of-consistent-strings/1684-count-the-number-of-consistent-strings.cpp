class Solution {
public:
    int m[26];
    int countConsistentStrings(string s, vector<string>& arr) {
        for(char c:s)m[c-'a']=1;
        
        int res=0;
        for(string &t:arr){
            bool b=1;
            for(char &c:t){
                if(m[c-'a']==0)
                    b=0;
            }
            if(b)res++;
        }
        return res;
    }
};