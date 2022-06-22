class Solution {
    String sort(String s){
        char c[]=s.toCharArray();
        Arrays.sort(c);
        s=String.valueOf(c);
        return s;
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>>m=new HashMap<String,List<String>>();
        
        List<List<String>>res=new ArrayList<>();
        
        for(int i=0;i<strs.length;i++){
            String s=strs[i];
            s=sort(s);
            if(m.containsKey(s)==false)
                m.put(s,new ArrayList<String>());
            m.get(s).add(strs[i]);
        }
        
        for(List<String> l:m.values()){
            res.add(l);
        }
        
        return res;
    }
}