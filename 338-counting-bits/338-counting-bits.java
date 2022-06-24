class Solution {
    public int[] countBits(int n) {
        int arr[]=new int[n+1];
        if(n>0)
            arr[1]=1;
        int j=0,i=2;
        while(i<=n){
            if((i&(i-1))==0)
                j=0;
            arr[i]=1+arr[j];
            i++;j++;
        }
        return arr;
    }
}