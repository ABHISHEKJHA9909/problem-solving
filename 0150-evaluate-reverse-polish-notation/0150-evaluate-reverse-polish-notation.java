class Solution {
    public int evalRPN(String[] tokens) {
        int len=tokens.length;
        
        Stack<Integer>st=new Stack<>();
        
        for(int i=0;i<len;++i){
            if(tokens[i].equals("+")){
                int y=st.pop();
                int x=st.pop();
                
                st.push(x+y);
            }
            else if(tokens[i].equals("-")){
                int y=st.pop();
                int x=st.pop();
                
                st.push(x-y);
            }
            else if(tokens[i].equals("*")){
                int y=st.pop();
                int x=st.pop();
                
                st.push(x*y);
            }
            else if(tokens[i].equals("/")){
                int y=st.pop();
                int x=st.pop();
                
                st.push(x/y);
            }
            else{
                
                st.push(Integer.valueOf(tokens[i]));
            }
        }
        
        return st.peek();
    }
}