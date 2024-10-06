class Solution {
    public String makeGood(String s) {
        Stack<Character>st=new Stack<>();
        int len=s.length();
        
        for(int i=0;i<len;++i){
            if(!st.isEmpty() && ((st.peek()+32)==s.charAt(i) || st.peek()==(s.charAt(i)+32))){
                st.pop();
            }
            else{
                st.push(s.charAt(i));
            }
        }
        
        StringBuilder sb=new StringBuilder();
        
        while(!st.empty()){
            sb.append(st.peek());
            st.pop();
        }
        
        return sb.reverse().toString();
    }
}