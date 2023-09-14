class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String,ArrayList<String>>m=new HashMap<String,ArrayList<String>>();
        
        for(List<String> s:tickets){
            String from=s.get(0);
            String to=s.get(1);
            
            if(m.get(from)==null){
                m.put(from,new ArrayList<String>());
            }
            
            m.get(from).add(to);
        }
        
        for(List<String> i:m.values()){
            Collections.sort(i);
        }
        
        Stack<String>s=new Stack<String>();
        s.push("JFK");
        List<String>res=new ArrayList<String>();
        
        while(!s.isEmpty()){
            if(m.get(s.peek())!=null && !m.get(s.peek()).isEmpty()){
                String t=m.get(s.peek()).get(0);
                m.get(s.peek()).remove(0);
                s.push(t);
            }
            else{
                res.add(s.peek());
                s.pop();
            }
        }
        
        Collections.reverse(res);
        
        return res;
    }
}