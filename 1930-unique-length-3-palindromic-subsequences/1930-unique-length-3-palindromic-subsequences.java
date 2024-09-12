class Solution {
    public int countPalindromicSubsequence(String s) {
        int len=s.length();
        int res=0;
        
        for(char c='a';c<='z';c+=1){
            boolean flag=false;
            Set<Character>st=new HashSet<>();
            int curr=0;
            for(int i=0;i<len;i++){
                if(!flag){
                    if(s.charAt(i)==c){
                        flag=true;
                    }
                }
                else{
                    if(s.charAt(i)==c){
                        curr=st.size();
                    }
                    st.add(s.charAt(i));
                }
            }
            res+=curr;
            // System.out.println(res);
        }
        
        return res;
    }
}