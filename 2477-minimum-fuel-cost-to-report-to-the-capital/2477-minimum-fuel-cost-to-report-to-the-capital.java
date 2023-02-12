class Solution {
    int n,seat;
    long res=0;
    
    private long rec(int i,int j,ArrayList<Integer>[]arr,long cnt){
        
        long x=0;
        for(int k:arr[i]){
            if(k!=j){
                x+=rec(k,i,arr,cnt+1);
            }
        }
        if(i==0)
            return x;
        else
            x+=1;
        // System.out.println(i+" "+x);
        res+=(x+seat-1)/seat;
        return x;
    }
    
    public long minimumFuelCost(int[][] roads, int seat) {
        n=roads.length;
        this.seat=seat;
        ArrayList<Integer> arr[]=new ArrayList[n+1];
        for(int i=0;i<n+1;i++)
            arr[i]=new ArrayList<Integer>();
        
        for(int i=0;i<n;i++){
            arr[roads[i][0]].add(roads[i][1]);
            arr[roads[i][1]].add(roads[i][0]);
        }
        
        rec(0,-1,arr,0);
        return res;
    }
}