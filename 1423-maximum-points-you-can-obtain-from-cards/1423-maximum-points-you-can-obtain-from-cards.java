class Solution {
    public int maxScore(int[] arr, int k) {
        int n=arr.length;
        int brr[]=new int[2*n];
        for(int i=0;i<n;i++)brr[i]=arr[i];
        for(int i=0;i<n;i++)brr[i+n]=arr[i];
        
        int kk=k,i=n-k,j=i,ans=0,res=0;
        while(j<n)
            res+=brr[j++];
        ans=Math.max(ans,res);
        j=0;
        while(kk!=0){
            res+=brr[j++]-brr[i++];
            ans=Math.max(ans,res);
            // System.out.println(res);
            kk--;
        }
        return ans;
    }
}