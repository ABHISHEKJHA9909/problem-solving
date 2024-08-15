class Solution {
    private String[] stringToArray(String s){
        List<String> lis=new ArrayList<>();
        int len=s.length();
        String curr="";
        
        for(int i=0;i<len;i++){
            if(s.charAt(i)==' '){
                lis.add(curr);
                curr="";
                continue;
            }
            curr+=s.charAt(i);
        }
        
        lis.add(curr);
        
        return lis.toArray(new String[0]);
    }
    
    
    public boolean wordPattern(String pattern, String s) {
        Map<Character,String>m1=new HashMap<>();
        Map<String,Character>m2=new HashMap<>();
        
        String arr[]=stringToArray(s);
        
        int len=pattern.length();
        
        if(arr.length!=len){
            return false;
        }
        
        for(int i=0;i<len;i++){
            if(m1.get(pattern.charAt(i))==null){
                if(m2.get(arr[i])!=null){
                    return false;
                }
                m1.put(pattern.charAt(i),arr[i]);
                m2.put(arr[i],pattern.charAt(i));
            }
            else{
                // System.out.println(m1.get(pattern.charAt(i))+" "+m2.get(arr[i]));
                // System.out.println(pattern.charAt(i)+" "+arr[i]);
                // System.out.println("false");
                if(!m1.get(pattern.charAt(i)).equals(arr[i]) || !m2.get(arr[i]).equals(pattern.charAt(i))){
                    return false;
                }
            }
        }
        
        return true;
    }
}