class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        
        for(string& s:words){
            ++m[s];
        }
        
        int res=0;
        bool b=false;
        
        for(auto &[s,y]:m){
            string t=s;reverse(t.begin(),t.end());
            
            if(s==t){
                res+=(4*(y/2));
                y%=2;
                if(y)
                    b=true;
            }
            else{
                if(m[s]==0 || m.find(t)==m.end() || m[t]==0)
                    continue;
                int x=min(m[s],m[t]);
                res+=(4*x);
                m[s]-=x;m[t]-=x;
            }
        }
        
        return res+(b?2:0);
    }
};