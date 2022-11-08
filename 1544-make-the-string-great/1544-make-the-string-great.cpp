class Solution {
public:
    int getabs(char c){
        if(islower(c))
            return c-'a';
        return c-'A';
    }
    
    string makeGood(string s) {
        stack<char>st;
        
        for(char&c:s){
            if(st.size()==0){
                st.push(c);
            }
            else{
                if(st.top()!=c && getabs(st.top())==getabs(c))
                    st.pop();
                else
                    st.push(c);
            }
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