class Solution {
public:
    bool valid(string &s){
        stack<char>st;
        for(char c:s){
            if(c=='(')
                st.push(')');
            else{
                if(st.size()==0)
                    return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
    
    void generateall(int n,string s,vector<string> &res){
        if(n==0){
            if(valid(s))
                res.push_back(s);
            return;
        }
        generateall(n-1,s+"(",res);
        generateall(n-1,s+")",res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generateall(2*n,"",res);
        return res;
    }
};