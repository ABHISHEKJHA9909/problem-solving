class Solution {
    public int minCost(String s, int[] arr) {
        int len=s.length();
        int res=0;
        int max=arr[0],sum=arr[0];
        
        for(int i=1;i<len;++i){
            if(s.charAt(i)==s.charAt(i-1)){
                sum+=arr[i];
                max=Math.max(max,arr[i]);
                continue;
            }
            res+=(sum-max);
            sum=arr[i];
            max=arr[i];
            // System.out.println(res);
        }
        
        return res+(sum-max);
    }
}