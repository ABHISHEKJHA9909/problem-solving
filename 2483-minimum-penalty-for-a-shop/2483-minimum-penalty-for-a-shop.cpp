class Solution {
public:
    int bestClosingTime(string s) {
        int cust=0;
        
        for(char &c:s){
            if(c=='Y')
                ++cust;
        }
        
        int res=-1,panelty=INT_MAX;
        int no_cust=0;
        
        for(int i=0;i<s.size();i++){
            
            if(panelty>cust+no_cust){
                panelty=cust+no_cust;
                res=i;
            }
            
            if(s[i]=='Y')
                --cust;
            else
                ++no_cust;
        }
        
        if(panelty>cust+no_cust){
                panelty=cust+no_cust;
                res=s.size();
        }
        
        
        return res;
    }
};