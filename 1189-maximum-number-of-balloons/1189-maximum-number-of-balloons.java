class Solution {
    public int maxNumberOfBalloons(String text) {
        int cnt[]=new int[26];
        
        int len=text.length();
        
        for(int i=0;i<len;i++){
            ++cnt[text.charAt(i)-'a'];
        }
        
        return Collections.min(List.of(cnt['b'-'a'],cnt['a'-'a'],cnt['l'-'a']/2,cnt['o'-'a']/2,cnt['n'-'a']));
    }
}