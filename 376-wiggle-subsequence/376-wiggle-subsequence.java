class Solution {
    public int wiggleMaxLength(int[] arr) {
        int n=(short)arr.length;          //length of array
        int res=1,prev=0,curr;
        
        for(int i=1;i<n;++i){
            curr=arr[i]-arr[i-1];
            
            if(prev<=0 && curr>0){
                ++res;
                prev=curr;
            }
            else if(prev>=0 && curr<0){
                ++res;
                prev=curr;
            }
            
        }
        
        return res;
    }
}