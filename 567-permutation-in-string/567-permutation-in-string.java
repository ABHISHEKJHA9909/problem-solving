class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int cnt[]=new int[26];
        
        for(int i=0;i<s1.length();++i){
            ++cnt[s1.charAt(i)-'a'];
        }
        
        for(int i=0,j=0,len=0;i<s2.length();++i){
            if(--cnt[s2.charAt(i)-'a']==-1){
                while(++cnt[s2.charAt(j++)-'a']!=0);
            }
            
            
            
            if(i-j+1==s1.length())
                return true;
            
        }
        
        return false;
    }
}