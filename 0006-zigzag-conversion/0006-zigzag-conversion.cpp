class Solution {
public:
    string convert(string s, int x) {
        if(x==1)
            return s;
        string res="";
        int n=s.size();
        int y=(x-1)*2,z=0;
        
        for(int i=x-1;i>=0;i--){
            int j=x-1-i;
            int k=0;
            // cout<<j<<' '<<y<<' '<<z;
            while(j<n){
                // cout<<j<<' ';
                if(k&1){
                    if(z==0){
                        k^=1;
                        continue;
                    }
                    res+=s[j];
                    j+=z;
                }
                else{
                    if(y==0){
                        k^=1;
                        continue;
                    }
                    res+=s[j];
                    j+=y;
                }
                k^=1;
            }
            
            y-=2;
            z+=2;
            // cout<<res<<endl;
        }
        
        return res;
    }
};