class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int ii=0,jj=0,i=0,j=0,r=arr.size(),c=arr[0].size(),cnt=1,k=0;
        vector<int> res;
        cout<<r*c<<endl;
        for(int cnt=1,n=r*c;cnt<=n;cnt++){
            if(!(i>=ii && j>=jj && i<r && j<c)){
                i-=dir[k][0];
                j-=dir[k][1];
                k+=1;k%=4;
                if(k==1)
                    ii++;
                else if(k==2)
                    c--;
                else if(k==3)
                    r--;
                else
                    jj++;
                i+=dir[k][0];
                j+=dir[k][1];
            }
            res.push_back(arr[i][j]);
            i+=dir[k][0];
            j+=dir[k][1];
        }
        
        return res;
    }
};