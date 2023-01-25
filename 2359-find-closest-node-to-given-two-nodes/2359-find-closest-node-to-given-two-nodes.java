class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n=edges.length;
        int arr[][]=new int[2][n];
        for(int i=0;i<n;i++){
            arr[0][i]=Integer.MAX_VALUE;
            arr[1][i]=Integer.MAX_VALUE;
        }
        
        int vis[]=new int[n];
        int step=0;
        
        while(true){
            vis[node1]=1;
            arr[0][node1]=step++;
            
            if(edges[node1]==-1||vis[edges[node1]]==1)
                break;
            node1=edges[node1];
        }
        
        Arrays.fill(vis,0);
        step=0;
        
        while(true){
            vis[node2]=1;
            arr[1][node2]=step++;
            
            if(edges[node2]==-1||vis[edges[node2]]==1)
                break;
            node2=edges[node2];
        }
        
        int curr=Integer.MAX_VALUE,res=-1;
        for(int i=0;i<n;i++){
            if(arr[0][i]==Integer.MAX_VALUE||arr[1][i]==Integer.MAX_VALUE)
                continue;
            if(curr>Math.max(arr[0][i],arr[1][i])){
                res=i;
                curr=Math.max(arr[0][i],arr[1][i]);
            }
            else if(curr==Math.max(arr[0][i],arr[1][i])){
                res=Math.min(res,i);
            }
            // System.out.println(i+"--->"+arr[0][i]+" "+arr[1][i]);
        }
        
        return res;
    }
}