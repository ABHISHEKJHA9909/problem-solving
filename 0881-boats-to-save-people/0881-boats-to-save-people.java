class Solution {
    public int numRescueBoats(int[] arr, int l) {
         int n=arr.length;
        
        Arrays.sort(arr);
        
        int i=0,j=n-1,curr=0;
        
        while(i<=j){
            if((arr[i]+arr[j])>l){
                j--;
            }
            else{
                i++;
                j--;
            }
            curr++;
        }
        
        return curr;
    }
}