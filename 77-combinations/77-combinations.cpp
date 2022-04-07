class Solution {
public:
    vector<vector<int>> res;
    void rec(int i,int k,int n,vector<int> curr){
        if(k==0){
            res.push_back(curr);
            return;
        }
        for(int j=i;j<=n;j++){
            curr.push_back(j);
            rec(j+1,k-1,n,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int x=(1<<n);
        
        for(int i=0;i<x;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    cnt++;
            }
            if(cnt==k){
                vector<int>curr;
                for(int j=0;j<n;j++){
                    if(i&(1<<j))
                        curr.push_back(j+1);
                }
                res.push_back(curr);
            }
        }
        
        return res;
    }
};