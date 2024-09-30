class Solution {
    public int minFlips(String t) {
        int a=0;
        int b=0;
        int cnta=0;
        int cntb=0;
        int res=Integer.MAX_VALUE;
        int len=t.length();
        
        String s=t+t;
        
        for(int i=0,j=0;i<2*len;++i){
            if((i&1)==1){
                if(s.charAt(i)=='1'){
                    ++cnta;
                }
                else{
                    ++cntb;
                }
            }
            else{
                if(s.charAt(i)=='1'){
                    ++cntb;
                }
                else{
                    ++cnta;
                }
            }
            if(i>=len-1){
                res=Math.min(res,Math.min(cnta,cntb));
                
                if((j&1)==1){
                    if(s.charAt(j)=='1'){
                        --cnta;
                    }
                    else{
                        --cntb;
                    }
                }
                else{
                    if(s.charAt(j)=='1'){
                        --cntb;
                    }
                    else{
                        --cnta;
                    }
                }
                ++j;
            }
        }
        
        return res;
    }
}