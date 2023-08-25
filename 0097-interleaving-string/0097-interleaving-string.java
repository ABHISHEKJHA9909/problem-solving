class Solution {
    
    public boolean rec(int i,int j,String s1,String s2,String s3,Map<String,Boolean>m){
        if(i==s1.length() && j==s2.length())
            return true;
        
        String s=i+"-"+j;
        if(m.get(s)!=null)
            return m.get(s);
        
        m.put(s,true);
        if(i<s1.length() && s1.charAt(i)==s3.charAt(i+j) && rec(i+1,j,s1,s2,s3,m))
            return true;
        if(j<s2.length() && s2.charAt(j)==s3.charAt(i+j) && rec(i,j+1,s1,s2,s3,m))
            return true;
        m.put(s,false);
        return false;
    }
    
    public boolean isInterleave(String s1, String s2, String s3) {
        if((s1.length()+s2.length())!=s3.length())
            return false;
        Map<String,Boolean>m=new HashMap<String,Boolean>();
        return rec(0,0,s1,s2,s3,m);
    }
}