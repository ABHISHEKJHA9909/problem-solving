class Solution {
public:
    int integerBreak(int n) {
        int res=INT_MIN;
        for(int i=2;i<=n;i++){
            int k=n/i;
            int l=n-k*i;
            // cout<<k<<' '<<l<<endl;
            int x=pow(k,i-l)*pow(k+1,l);
            // cout<<x<<endl;
            res=max(res,x);
        }
        return res;
    }
};