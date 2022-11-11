class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        
        for(char c:s){
            if(st.size() && st.top()==c)
                st.pop();
            else
                st.push(c);
        }
        
        s="";
        while(st.size()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        return s;
    }
};