class Solution {
    public int countCharacters(String[] words, String chars) {
        int freq[]=new int[26];
        int len=chars.length();
        
        for(int i=0;i<len;i++){
            ++freq[chars.charAt(i)-'a'];
        }
        
        int result=0;
        
        for(String s:words){
            len=s.length();
            int curr[]=new int[26];
            for(int i=0;i<len;i++){
                ++curr[s.charAt(i)-'a'];
            }
            
            boolean flag=true;
            
            for(int i=0;i<26;i++){
                if(curr[i]>freq[i]){
                    flag=false;
                }
            }
            
            if(flag){
                result+=len;
            }
        }
        
        return result;
    }
}