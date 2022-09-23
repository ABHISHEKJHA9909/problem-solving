class Solution {
public:
    int concatenatedBinary(int n) {
        int res=0,pow=1;
        for(int i=n;i>=1;i--){
            int j=i;
            while(j){
                if(j&1){
                    res+=pow;
                    res%=1000000007;
                }
                pow*=2;
                pow%=1000000007;
                j=j>>1;
            }
        }
        return res;
    }
};