class Solution {
    public boolean hasAllCodes(String t, int k) {
        
        Set<Integer>s=new HashSet<>();
        int len=t.length();
        int curr=0;
        
        for(int i=0;i<len;i++){
            if(t.charAt(i)=='1'){
                curr|=1;
            }
            // System.out.println(curr);
            
            if(i>=(k-1)){
                s.add(curr);
                curr&=~(1<<(k-1));
            }
            curr<<=1;
        }
        
        return s.size()==Math.pow(2,k);
    }
}