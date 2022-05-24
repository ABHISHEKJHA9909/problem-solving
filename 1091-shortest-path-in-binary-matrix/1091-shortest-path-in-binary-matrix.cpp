class Solution {
public:
    int arr[100][100];
    int n,m;
    
    bool is(int i,int j){
        return  i>=0 && i<n && j>=0 && j<m;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int l=1;
        
        grid[0][0]=1;
        while(q.size()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                auto [x,y]=q.front();
                // cout<<x<<' '<<y<<' '<<grid[x][y]<<endl;
                q.pop();
                arr[x][y]=l;
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(is(x+i,y+j) && grid[i+x][j+y]==0){
                                q.push({x+i,y+j});
                                grid[x+i][y+j]=1;
                        }
                    }
                }
            }
            // cout<<"------"<<endl;
            l++;
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<arr[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        if(arr[n-1][m-1]==0)
            return -1;
        return arr[n-1][m-1];
    }
};