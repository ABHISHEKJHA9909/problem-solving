class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long i=1,j=(int)1e14;
        
        int res=0;
        
        while(i<=j){
            int mid=(int)(i+(j-i)/2);
            long curr=0;
            for(int k:piles){
                curr+=((k+mid-1)/mid);
            }
            if(curr<=h){
                res=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return res;
    }
}