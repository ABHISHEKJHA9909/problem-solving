class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character>m1=new HashMap<Character,Character>();
        Map<Character,Character>m2=new HashMap<Character,Character>();
        
        int sLen=s.length();
        int tLen=t.length();
        
        if(sLen!=tLen){
            return false;
        }
        
        for(int i=0;i<sLen;i++){
            if(m1.get(s.charAt(i))==null){
                if(m2.get(t.charAt(i))!=null){
                    return false;
                }
                m1.put(s.charAt(i),t.charAt(i));
                m2.put(t.charAt(i),s.charAt(i));
            }
            else{
                if( (m1.get(s.charAt(i))!=t.charAt(i)) || (m2.get(t.charAt(i))!=s.charAt(i)) ){
                    return false;
                }
            }
        }
        
        return true;
    }
}