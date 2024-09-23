class Solution {
    public int trap(int[] height) {
        int i=0;
        int j=height.length-1;
        int res=0;
        int lmax=height[i];
        int rmax=height[j];
        
        while(i<j){
            // System.out.print(i+" "+j);
            if(height[i]<height[j]){
                lmax=Math.max(lmax,height[++i]);
                if(Math.min(lmax,rmax)>height[i])
                    res+=(Math.min(lmax,rmax)-height[i]);
            }
            else{
                rmax=Math.max(rmax,height[--j]);
                if(Math.min(lmax,rmax)>height[j])
                    res+=(Math.min(lmax,rmax)-height[j]);
            }
            // System.out.println(" -> "+res+" "+lmax+" "+rmax);
        }
        
        return res;
    }
}