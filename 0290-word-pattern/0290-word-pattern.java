class Solution {
    
    
    public boolean wordPattern(String pattern, String s) {
        Map<Character,String>m1=new HashMap<>();
        Map<String,Character>m2=new HashMap<>();
        
        String arr[]=s.split(" ");
        
        int len=pattern.length();
        
        if(arr.length!=len){
            return false;
        }
        
        for(int i=0;i<len;i++){
            
            if(m1.get(pattern.charAt(i))==null){
                m1.put(pattern.charAt(i),arr[i]);
            }
            if(m2.get(arr[i])==null){
                m2.put(arr[i],pattern.charAt(i));
            }
            
            if(!m1.get(pattern.charAt(i)).equals(arr[i]) || !m2.get(arr[i]).equals(pattern.charAt(i))){
                return false;
            }
        }
        
        return true;
    }
}