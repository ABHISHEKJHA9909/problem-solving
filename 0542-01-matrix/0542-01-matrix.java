class Solution {
    class pair{
        public int f,s;
        pair(int f,int s){
            this.f=f;
            this.s=s;
        }
    }
    
    boolean check(int i,int j,int r,int c,int[][] res){
        return i>=0 && i<r && j>=0 && j<c && res[i][j]==-1;
    }
    
    public int[][] updateMatrix(int[][] mat) {
        
        //initlize result array
        int r=mat.length,c=mat[0].length;
        int res[][]=new int[r][c];
        
        Queue<pair> q=new LinkedList<>();
        
        //putting zero distance 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.add(new pair(i,j));
                }
                else{
                    res[i][j]=-1;
                }
            }
        }
        
        int curr=1;
        while(q.size()!=0){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                int x=q.peek().f;
                int y=q.poll().s;
                
                if(check(x+1,y,r,c,res)){
                    res[x+1][y]=curr;
                    q.add(new pair(x+1,y));
                }
                if(check(x-1,y,r,c,res)){
                    res[x-1][y]=curr;
                    q.add(new pair(x-1,y));
                }
                if(check(x,y+1,r,c,res)){
                    res[x][y+1]=curr;
                    q.add(new pair(x,y+1));
                }
                if(check(x,y-1,r,c,res)){
                    res[x][y-1]=curr;
                    q.add(new pair(x,y-1));
                }
                
            }
            
            ++curr;
        }
        
        return res;
    }
}