class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        
        int sLen=s.length;
        int gLen=g.length;
        
        int satisfy=0;
        
        for(int i=0,j=0;i<gLen &&j<sLen;){
            if(s[j]<g[i]){
                ++j;
            }
            else{
                ++satisfy;
                ++j;
                ++i;
            }
        }
            
        return satisfy;
    }
}