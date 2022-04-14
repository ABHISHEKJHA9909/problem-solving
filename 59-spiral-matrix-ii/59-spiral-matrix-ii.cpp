class Solution {
public:
    vector<vector<int>> m={{1,0},{0,1},{-1,0},{0,-1}};
    int vis[21][21];
    
    bool is(int i,int j,int n){
        if(i<0 || i==n || j<0 || j==n)
            return true;
        return vis[i][j]==1;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>  res( n,vector<int> ( n));
        
        for(int i=0,j=0,curr=1,x=0,p=1;p<=n*n;p++){
            if(is(i,j,n)){
                j-=m[x][0];
                i-=m[x][1];
                x+=1;
                x%=4;
                j+=m[x][0],i+=m[x][1];
            }
            vis[i][j]=1;
            res[i][j]=curr++;
            // cout<<i<<' '<<j<<' '<<curr<<endl;
            j+=m[x][0],i+=m[x][1];
        }
        
        return res;
    }
};