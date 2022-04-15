class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int n=0;
        res.push_back({1});
        while(--numRows){
            vector<int>curr;
            curr.push_back(1);
            
            int i=1;
            while(i<res[n].size()){
                curr.push_back(res[n][i-1] + res[n][i]);
                i++;
            }
            curr.push_back(1);
            res.push_back(curr);
            n++;
        }
        
        return res;
    }
};