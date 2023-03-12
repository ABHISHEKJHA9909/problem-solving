class Solution {
    public void rotate(int[] arr, int k) {
        int n=arr.length;
        
        k%=n ;
        
        for(int i=k,cnt=0,curr=0,temp=arr[0];cnt<n;i+=k){
            i%=n;
            
            int currtemp=arr[i];
            arr[i]=temp;
            temp=currtemp;
            cnt++;
            // System.out.println(i);
            if(i==curr){
                i+=1;i%=n;
                temp=arr[i];
                curr=i;
                continue;
            }
        }
    }
}