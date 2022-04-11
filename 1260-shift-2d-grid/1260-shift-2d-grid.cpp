class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& arr, int k) {
        int r=arr.size(),c=arr[0].size();
        k%=(r*c);
        int i=(k/c), j=k%c;
        int l=0,b=0,n=r*c;
        vector<vector<int>> res(r,vector<int>(c));
        
        while(n--){
            res[i][j]=arr[l][b];
            // cout<<i<<' '<<j<<endl;
            j++;
            b++;
            if(j%c==0)i++,j=0;
            if(b%c==0)l++,b=0;
            if(i!=0 && i%r==0)i=0,j=0;
        }
        
        return res;
    }
};