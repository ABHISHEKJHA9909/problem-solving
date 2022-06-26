class Solution {
    public int maxScore(int[] arr, int k) {
        int n=arr.length;
        int res=0,ans=0;
        for(int i=n-k;i<n;++i)
            res+=arr[i];
        ans=Math.max(ans,res);
        for(int j=0,i=n-k;k!=0;++j,++i,--k){
            res+=arr[j]-arr[i];
            ans=Math.max(ans,res);
        }
        return ans;
    }
}