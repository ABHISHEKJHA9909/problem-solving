class Solution {
    private static final int MOD=1000000007;
    
    public int sumSubarrayMins(int[] arr) {
        int len=arr.length;
        int res=0;
        Stack<Integer>s=new Stack<>();
        int[] min=new int[len];
        
        
        for(int i=0;i<len;++i){
            while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
                s.pop();
            }
            
            if(s.isEmpty()){
                min[i]=(i+1)*arr[i];
            }
            else{
                min[i]=((i-s.peek())*arr[i] + min[s.peek()])%MOD;
            }
            
            res+=min[i];
            res%=MOD;
            s.push(i);
        }
        
        return res;
    }
}