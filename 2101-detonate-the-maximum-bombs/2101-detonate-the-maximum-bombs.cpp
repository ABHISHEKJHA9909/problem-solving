class Solution {
public:
    vector<int>arr[101];
    int n;
    int curr=0;
    
    void dfs(int i,vector<int> &vis){
        if(vis[i]==0){
            // cout<<i<<' '<<vis[i]<<' ';
            curr++;
            vis[i]=1;
            for(int j:arr[i]){
                dfs(j,vis);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& b) {
        n=b.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                long long x=(b[i][0]-b[j][0]);
                long long y=(b[i][1]-b[j][1]);
                long long r=x*x+y*y;
                if(r<=(long long)b[i][2]*(long long)b[i][2]){
                    arr[i].push_back(j);
                }
            }
        }
        
//         for(int i=0;i<n;i++){
//             cout<<i<<'=';
//             for(int j:arr[i])
//                 cout<<j<<' ';
//             cout<<endl;
//         }
        
        int res=0;
        for(int i=0;i<n;i++){
            vector<int>vis(101,0);
            dfs(i,vis);
            // cout<<endl;
            res=max(res,curr);
            curr=0;
        }
        return res;
    }
};