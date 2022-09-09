class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        
        int n=arr.size(),a=arr[n-1][0],b=arr[n-1][1],lmax=arr[n-1][1];
        

        int ans=0;
        
        for(int i=n-2;i>=0;i--){
            if(arr[i][0]<arr[i+1][0]){
                b=max(lmax,b);
                lmax=max(b,arr[i][1]);
            }
            if(arr[i][0]<a && arr[i][1]<b)
                ans++;
        }
        
        return ans;
    }
};