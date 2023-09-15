class Solution {
    
    int find(int []arr, int i){
        if(arr[i]==i)
            return i;
        return find(arr,arr[i]);
    }
    
    void union(int arr[],int i,int j){
        i=find(arr,i);
        j=find(arr,j);
        
        arr[i]=j;
    }
    
    public int minCostConnectPoints(int[][] points) {
        int len=points.length;
        
        ArrayList<Integer[]>arr=new ArrayList<>();
        
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                arr.add(new Integer[]{i,j,Math.abs(points[i][0]-points[j][0])+
                                          Math.abs(points[i][1]-points[j][1])});
            }
        }
        
        Collections.sort(arr,(a,b)->{return a[2]-b[2];});
        
        int brr[]=new int[len];
        
        for(int i=0;i<len;i++){
            brr[i]=i;
        }
        
        int res=0;
        
        for(int i=0;i<arr.size();i++){
            int a=arr.get(i)[0];
            int b=arr.get(i)[1];
            int c=arr.get(i)[2];
            
            if(find(brr,a)!=find(brr,b)){
                union(brr,a,b);
                res+=c;
            }
        }
        
        return res;
    }
}