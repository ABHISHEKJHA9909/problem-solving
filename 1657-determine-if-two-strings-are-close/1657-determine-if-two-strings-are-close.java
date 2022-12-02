class Solution {
    public boolean closeStrings(String s, String t) {
        if(s.length()!=t.length())
            return false;
        
        int []cnt=new int[26];
        int []bnt=new int[26];
        
        for(int i=0;i<s.length();i++){
            cnt[s.charAt(i)-'a']++;
            bnt[t.charAt(i)-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(cnt[i]==0 && bnt[i]!=0 || bnt[i]==0 && cnt[i]!=0)
                return false;
        }
        
        Arrays.sort(cnt);
        Arrays.sort(bnt);
        
        for(int i=0;i<26;i++){
            if(cnt[i]!=bnt[i])
                return false;
        }
        
        return true;
    }
}