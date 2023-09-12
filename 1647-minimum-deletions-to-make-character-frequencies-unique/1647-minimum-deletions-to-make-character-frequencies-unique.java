
class Solution {
    public int minDeletions(String s) {
        
        int char_count[]=new int[26];
        
        int mx=0;
        
        for(int i=0;i<s.length();i++){
            ++char_count[s.charAt(i)-'a'];
            mx=Math.max(mx,char_count[s.charAt(i)-'a']);
        }
        
        int cnt[]=new int[mx+1];
        
        for(int i=0;i<26;i++){
            ++cnt[char_count[i]];
        }
        
        int res=0;
        
        for(int i=mx;i>0;i--){
            if(cnt[i]>1){
                res+=cnt[i]-1;
                cnt[i-1]+=(cnt[i]-1);
            }
        }
        
        return res;
        
    }
}