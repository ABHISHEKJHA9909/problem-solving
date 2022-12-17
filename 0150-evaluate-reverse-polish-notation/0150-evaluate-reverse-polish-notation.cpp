class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>t;
        for(string &s:tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                long x=t.top();t.pop();
                long y=t.top();t.pop();
                if(s=="+")
                    t.push(x+y);
                else if(s=="-")
                    t.push(y-x);
                else if(s=="*")
                    t.push(x*y);
                else
                    t.push(y/x);
            }
            else{
                t.push(stoi(s));
            }
        }
        
        return t.top();
    }
};