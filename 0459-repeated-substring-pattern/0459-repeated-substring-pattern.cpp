class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        
        for(int i=n/2;i>=1;--i){
            if(n%i==0){
                int len=i;
                int j=0;
                for(;len<n;++j,++len){
                    if(s[j]!=s[len])
                        break;
                }
                
                if(len==n && j==n-i)
                    return true;
            }
        }
        
        return false;
    }
    
};