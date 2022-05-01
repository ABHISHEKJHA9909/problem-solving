class Solution {
public:
    string rec(string s){
        stack<char>st;
        for(char c:s){
            if(c=='#'){
                if(st.size())
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
    bool backspaceCompare(string s, string t) {
        return rec(s)==rec(t);
    }
};