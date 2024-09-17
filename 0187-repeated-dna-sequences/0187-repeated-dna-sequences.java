class Solution {
    private long getHash(String s){
        long hash=0;
        for(int i=0;i<10;++i){
            if(s.charAt(i)=='A'){
                hash|=(1L<<(i*4+0));
            }
            else if(s.charAt(i)=='C'){
                hash|=(1L<<(i*4+1));
            }
            else if(s.charAt(i)=='G'){
                hash|=(1L<<(i*4+2));
            }
            else{
                hash|=(1L<<(i*4+3));
            }
        }
        return hash;
    }
    
    private String getString(long hash){
        StringBuilder sb=new StringBuilder();
        
        while(hash!=0){
            long curr=hash&15;
            if(curr==1){
                sb.append('A');
            }
            else if(curr==2){
                sb.append('C');
            }
            else if(curr==4){
                sb.append('G');
            }
            else{
                sb.append('T');
            }
            hash>>=4;
        }
        
        return sb.toString();
    }
    public List<String> findRepeatedDnaSequences(String s) {
        Map<Long,Integer>m=new HashMap<>();
        int len=s.length();
        
        for(int i=9;i<len;i++){
            long hash=getHash(s.substring(i-9,i+1));
            m.put(hash,m.getOrDefault(hash,0)+1);
        }
        
        List<String>res=new ArrayList<>();
        
        for(Map.Entry<Long,Integer> k:m.entrySet()){
            if(k.getValue()>1){
                res.add(getString(k.getKey()));
            }
        }
        
        return res;
    }
}