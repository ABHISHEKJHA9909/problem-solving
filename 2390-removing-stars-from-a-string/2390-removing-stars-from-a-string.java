class Solution {
    public String removeStars(String s) {
        Stack<Character>st=new Stack<>();
        
        for(int i=0,l=s.length();i<l;i++){
            if(s.charAt(i)=='*')
                st.pop();
            else
                st.push(s.charAt(i));
        }
        
        String res="";
        
        while(st.size()!=0){
            res=st.peek()+res;
            st.pop();
        }
        
        return res;
    }
}