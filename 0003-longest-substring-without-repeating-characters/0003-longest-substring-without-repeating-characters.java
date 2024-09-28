class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res=0;
        int len=s.length();
        boolean[] flag=new boolean[256];
        
        for(int i=0,j=0;i<len;++i){
            int curr=s.charAt(i);
            
            while(flag[curr]){
                flag[s.charAt(j++)]=false;
            }
            
            flag[curr]=true;
            res=Math.max(res,i-j+1);
        }
        
        return res;
    }
}