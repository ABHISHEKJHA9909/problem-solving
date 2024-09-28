class Solution {
    public int characterReplacement(String s, int k) {
        int len=s.length();
        int res=0;
        
        for(char c='A';c<='Z';++c){
            for(int i=0,j=0,cnt=0;i<len;++i){
                if(s.charAt(i)!=c){
                    ++cnt;
                }
                
                while(cnt>k){
                    if(s.charAt(j++)!=c){
                        --cnt;
                    }
                }
                
                res=Math.max(res,i-j+1);
            }
        }
        
        return res;
    }
}