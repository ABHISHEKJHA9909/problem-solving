class Solution {
public:
    vector<vector<int>>res;
    vector<int>curr;
    vector<int>vis;
    int n;
    
    void dfs(vector<vector<int>>& arr,int i){
        if(i==n-1){
            curr.push_back(n-1);
            res.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(i);
        vis[i]=1;
        for(int &j:arr[i]){
            if(vis[j]==0){
                dfs(arr,j);
            }
        }
        vis[i]=0;
        curr.pop_back();
    }
    

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& arr) {
        
        n=arr.size();
        vis=vector<int>(n);
        
        dfs(arr,0);

        return res;
    }
};