class Solution {
public:
    vector<int> arr[100005];
    int rank[100005];
    vector<vector<int>>res;
    
    int dfs(int curr,int j){
        if(rank[curr]>-2){
            return rank[curr];
        }
        int rl=j;
        rank[curr]=rl;
        for(int neb:arr[curr]){
            if(rank[neb]==j-1){
                continue;
            }
            int x=dfs(neb,j+1);
            rl=min(rl,x);
            if(x>j){
                res.push_back({min(neb,curr),max(neb,curr)});
            }
        }
        rank[curr]=rl;
        return rank[curr];
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        for(auto i:conn){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        for(int &i:rank)
            i=-2;
        dfs(0,0);
        return res;
    }
};