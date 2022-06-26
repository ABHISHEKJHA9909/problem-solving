class Solution {
    public int maxScore(int[] arr, int k) {
        int n=arr.length;
        int kk=k,i=n-k,j=i,ans=0,res=0;
        while(j<n)
            res+=arr[j++];
        ans=Math.max(ans,res);
        j=0;
        while(kk!=0){
            res+=arr[j++]-arr[i++];
            ans=Math.max(ans,res);
            kk--;
        }
        return ans;
    }
}