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
        rec(1,k,n,{});
        return res;
    }
};