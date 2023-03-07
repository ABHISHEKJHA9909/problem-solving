class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long  i=1,j=(long)1e15;
        
        long res=0;
        while(i<=j){
            long mid=i+(j-i)/2;
            
            long curr=0;
            for(int k:time){
                curr+=(mid/k);
                if(curr>totalTrips)
                    break;
            }
            
            // System.out.println(mid+"  "+curr);
            if(curr>=totalTrips){
                res=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        
        return res;
    }
}