class Solution {
public:
    void rec(int n,int k,vector<vector<int>>& res,vector<int>& curr){
        if(k==0){
            res.push_back(curr);
            return;
        };
        for(int i=n;i>=1;i--){
            curr.push_back(i);
            rec(i-1,k-1,res,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int>curr;
        rec(n,k,res,curr);
        return res;
    }
};