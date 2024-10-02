class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int len=arr.length;
        
        Arrays.sort(arr);
        
        int minSum=Integer.MAX_VALUE;
        int res=-1;
        
        for(int i=0,j=0,sum=0;i<len;++i){
            sum+=Math.abs(arr[i]-x);
            
            // System.out.println(sum);
            
            if(i>=k-1){
                if(sum<minSum){
                    minSum=sum;
                    res=j;
                }
                sum-=Math.abs(arr[j]-x);
                ++j;
            }
        }
        
        List<Integer>result=new ArrayList<>();
        
        for(int l=res;l<(res+k);++l){
            result.add(arr[l]);
        }
        
        return result;
    }
}