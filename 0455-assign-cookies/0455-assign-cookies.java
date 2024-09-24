class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        
        int sLen=s.length;
        int gLen=g.length;
        
        int satisfy=0;
        
        for(int i=0,j=0;i<gLen ;++i){
            while(j<sLen && s[j]<g[i]){
                ++j;
            }
            if(j==sLen){
                break;
            }
            ++satisfy;
            ++j;
        }
            
        return satisfy;
    }
}