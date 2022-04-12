class Solution {
public:
    int r,c;
    bool check(int i,int j){
        if(i<0 || i>=r || j<0 ||j>=c)
            return 0;
        return 1;
    }
    pair<int,int> cnt(int r,int c,vector<vector<int>> & arr){
        int z=0,o=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(check(i+r,j+c)){
                    if(i==0 && j==0)
                        continue;
                    if(arr[i+r][j+c]==0)
                        z++;
                    else
                        o++;
                }
            }
        }
        // cout<<z<<o<<endl;
        return {z,o};
    }
    
    
    void gameOfLife(vector<vector<int>>& arr) {
        r=arr.size();
        c=arr[0].size();
        vector<vector<int>> res(r,vector<int>(c));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=arr[i][j];
                pair<int,int>p=cnt(i,j,arr);
                if(arr[i][j]==1 && ( p.second<2 || p.second>3)){
                    res[i][j]=0;
                }
                else{
                    if(p.second==3)
                        res[i][j]=1;
                }
            }
        }
        
        arr=res;
        
    }
};