class Solution {
    public int trap(int[] arr) {
        int n=arr.length;
        
        int l[]=new int[n];
        int r[]=new int[n];
        for(int i=0,curr=arr[i];i<n;i++){
            curr=Math.max(curr,arr[i]);
            l[i]=curr;
        }
        for(int j=n-1,curr=arr[j];j>=0;j--){
            curr=Math.max(curr,arr[j]);
            r[j]=curr;
        }
        int res=0;
        // for(int i:arr)
        //     System.out.print(i+" ");
        // System.out.println();
        // for(int i:l)
        //     System.out.print(i+" ");
        // System.out.println();
        // for(int i:r)
        //     System.out.print(i+" ");
        
        for(int i=0;i<n;i++){
            res+=Math.min(l[i],r[i])-arr[i];
        }
        return res;
    }
}