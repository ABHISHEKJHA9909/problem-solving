class Solution {
public:
    string gcdOfStrings(string s, string t) {
        int n=s.size(),m=t.size();
        
        
        int gcd=__gcd(n,m);
        int i=0,j=gcd;
        
        cout<<gcd;
        while(j<m){
            if(t[i++]!=t[j++])
                return "";
        }
        
        i=0,j=0;
        while(i<n){
            if(s[i++]!=t[j++])
                return "";
            j%=m;
        }
        if(j%gcd!=0)
            return "";
        return s.substr(0,gcd);
    }
};