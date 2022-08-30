class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        if(arr.size()==0 || arr[0].size()==0)
            return 0;
        
        int r=arr.size(),c=arr[0].size();
        priority_queue<vector<int>>pq;
        
        vector<vector<int>>vis(r,vector<int>(c,0));
        
        for(int i=0;i<r;i++){
            vis[i][0]=vis[i][c-1]=1;
            pq.push({-arr[i][0],i,0});
            pq.push({-arr[i][c-1],i,c-1});
        }
        
        for(int j=0;j<c;j++){
            vis[0][j]=vis[r-1][j]=1;
            pq.push({-arr[0][j],0,j});
            pq.push({-arr[r-1][j],r-1,j});
        }
        
        int dirs[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
        int res=0;
        
        while(pq.size()){
            vector<int> curr=pq.top();
            pq.pop();
            int h=-curr[0];
            
            for(auto &dir:dirs){
                int i=curr[1]+dir[0],j=curr[2]+dir[1];
                if(i<0||i>=r||j<0||j>=c)
                    continue;
                if(vis[i][j]==0){
                    vis[i][j]=1;
                    if(arr[i][j]<h)
                        res+=(h-arr[i][j]);
                    pq.push({-max(arr[i][j],h),i,j});
                }
            }
        }
        
        
        return res;
    }
};