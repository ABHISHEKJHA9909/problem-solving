class Solution {
    public long distinctNames(String[] ideas) {
        HashSet<Integer>[] cnt=new HashSet[26];
        for(int i=0;i<26;i++)
            cnt[i]=new HashSet<Integer>();
        for(String s:ideas)
            cnt[s.charAt(0)-'a'].add(s.substring(1).hashCode());
        
        long res=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long c1=0,c2=0;
                for(int c:cnt[i])
                    if(!cnt[j].contains(c))c1++;
                
                for(int c:cnt[j])
                    if(!cnt[i].contains(c))c2++;
                
                res+=(c1*c2);
            }
        }
        
        return res*2;
    }
}