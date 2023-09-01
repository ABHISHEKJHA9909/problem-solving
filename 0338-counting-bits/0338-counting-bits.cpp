class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)
            return {0};
        if(n==1)
            return {0,1};
        
        vector<int>res={0,1};
        
        for(int k=1;res.size()<=n;k++){
            int _pow=1<<k;
            for(int j=0;j<_pow && res.size()<=n;j++){
                res.push_back(res[j]+1);
            }
        }
        
        return res;
    }
};