class Solution {
public:
    void solve(int i,int j,string s,vector<string> &res){
        if(j==0){
            res.push_back(s);
            return;
        }
        if(i>0)
            solve(i-1,j,s+'(',res);
        if(j>i)
            solve(i,j-1,s+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res; 
        solve(n,n,"",res);
        return res;
    }
};