class Solution {
    public int minSwaps(String s) {
        int neg=0;
        int sum=0;
        int len=s.length();
        
        for(int i=0;i<len;i++){
            if(s.charAt(i)=='['){
                ++neg;
            }
            else{
                --neg;
            }
            if(neg<0){
                ++sum;
                neg=0;
            }
        
        }
        if(sum<=1){
            return sum;
        }
        return (sum+1)/2;
    }
}