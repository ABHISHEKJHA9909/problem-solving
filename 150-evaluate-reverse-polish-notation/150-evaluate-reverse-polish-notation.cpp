class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        
        for(string &t:tokens){
            if(t.back()>='0'&&t.back()<='9'){
                s.push(stoi(t));
            }
            else{
                int second=s.top();s.pop();
                int first=s.top();s.pop();
                if(t=="+")
                    first+=second;
                else if(t=="-")
                    first-=second;
                else if(t=="*")
                    first*=second;
                else
                    first/=second;
                s.push(first);
            }
        }
        
        return s.top();
    }
};