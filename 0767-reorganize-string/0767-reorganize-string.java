class Solution {
    public String reorganizeString(String s) {
        
        int cnt[]=new int[26];
        
        int max=0;
        int c=0;
        
        for(int i=0;i<s.length();i++){
            cnt[s.charAt(i)-'a']++;
            if(cnt[s.charAt(i)-'a']>max){
                max=cnt[s.charAt(i)-'a'];
                c=s.charAt(i)-'a';
            }
        }
        
        
        if(max>(s.length()+1)/2)
            return "";
        
        Character arr[]=new Character[s.length()];
        
        int idx=0;
        while(cnt[c]>0){
            arr[idx]=(char)('a'+c);
            idx+=2;
            cnt[c]--;
        }
        
        for(int i=0;i<26;i++){
            while(cnt[i]>0){
                if(idx>=s.length()){
                    idx=1;
                }
                arr[idx]=(char)('a'+i);
                idx+=2;
                cnt[i]--;
            }
        }
        
        
        
        String res="";
        
        for(int i=0;i<s.length();i++){
            res+=arr[i];
        }
        
        return res;
    }
}