class Solution {
    public int maximumUnits(int[][] nums, int ts) {
        Arrays.sort(nums,new Comparator<int[]>(){
            public int compare(int[] a,int[] b){
                if(a[1]>b[1])
                    return -1;
                if(a[1]<b[1])
                    return 1;
                return 0;
            }
        });
        
        int res=0;
        
        for(int i=0;i<nums.length && ts!=0; i++){
            if(ts>=nums[i][0]){
                res+=nums[i][0]*nums[i][1];
                ts-=nums[i][0];
            }
            else{
                res+=ts*nums[i][1];
                ts=0;
            }
        }
        
        return res;
    }
}