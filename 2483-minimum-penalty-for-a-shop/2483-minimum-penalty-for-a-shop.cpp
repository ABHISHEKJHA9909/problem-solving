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
        int current_panelty=0;
        
        for(int i=0;i<s.size();i++){
            current_panelty=(cust+no_cust);
            
            if(panelty>current_panelty){
                panelty=current_panelty;
                res=i;
            }
            
            if(s[i]=='Y')
                --cust;
            else
                ++no_cust;
        }
        
        current_panelty=(cust+no_cust);
        if(panelty>current_panelty){
                panelty=current_panelty;
                res=s.size();
        }
        
        
        return res;
    }
};