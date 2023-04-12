class Solution {
    public String simplifyPath(String s) {
        Stack<String>st=new Stack<String>();
        
        int n=s.length();
        
        for(int i=0;i<n;){
            String curr="";
            int j=i;
            
            if(s.charAt(i)=='/'){
                while(i<n && s.charAt(i)==s.charAt(j))
                    i++;
                if(st.size()==0 || st.peek()!="/")
                    st.push("/");
            }
            else if(s.charAt(i)=='.'){
                while(i<n && s.charAt(i)!='/')
                    curr+=s.charAt(i++);
                if(curr.equals(".")){
                    continue;
                }
                else if(curr.equals("..")){
                    if(st.size()!=0)
                        st.pop();
                    if(st.size()!=0)
                        st.pop();
                }
                else{
                    st.push(curr);
                }
            }
        
            else{
                while(i<n && s.charAt(i)!='/')
                    curr+=s.charAt(i++);
                st.push(curr);
            }
        }
        
        String res="";
        if(st.size()!=0  && st.peek()=="/")
            st.pop();
        
        while(st.size()!=0){
            res=st.peek()+res;
            st.pop();
        }
        
        if(res=="")
            return "/";
        
        return res;
    }
}