class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int c=0;
        
        for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0;i--,j--){
            int sum=(i>=0?a[i]-'0':0)+(j>=0?b[j]-'0':0)+c;
            if(sum==0){
                res+="0";
            }
            else if(sum==1){
                res+="1";
                c=0;
            }
            else if(sum==2){
                res+="0";
                c=1;
            }
            else{
                res+="1";
                c=1;
            }
            
        }
        if(c)
            res+="1";
        
        reverse(res.begin(),res.end());
        return res;
    }
};