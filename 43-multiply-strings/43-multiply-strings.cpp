class Solution {
public:
    string multiply(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int> arr(n+m+5,0);
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        
        
        for(int i=0;i<m;i++){
            int n1=t[i]-'0',c=0;
            for(int j=0;j<n;j++){
                int n2=s[j]-'0';
                arr[i+j]+=(n1*n2+c);
                c=(arr[i+j])/10;
                arr[i+j]%=10;
            }
            if(c)
                arr[i+n]+=c;
        }
        
        reverse(arr.begin(),arr.end());
        int i=0;n=arr.size();
        while(i<n && arr[i]==0){i++;}
        s="";
        while(i<n){
            s+=('0'+arr[i++]);
        }
        if(s=="")
            return "0";
        return s;
    }
};