class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res=new ArrayList<>();
        HashMap<String,Integer>m=new HashMap<String,Integer>();
        
        for(String s:strs){
            char []ch=s.toCharArray();
            Arrays.sort(ch);
            String t=String.copyValueOf(ch);
            
            if(m.get(t)==null){
                m.put(t,res.size());
                res.add(new ArrayList<String>());
            }
            
            res.get(m.get(t)).add(s);
        }
        return res;
    }
}