class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size() ,l=words[0].size(),len=words.size();
        
        unordered_map<string,int>m;
        vector<int>res;
        
        for(string i:words)m[i]++;
        
        for(int i=0;i<l;i++){
            
            int left=i,right=i;
            
            while(right<n-l+1){
                string curr=s.substr(right,l);
                if(--m[curr]==-1){
                    if(right-left==l*len){
                        res.push_back(left);
                    }
                    // cout<<left<<' '<<right<<endl;
                    while(left<n-l+1 && ++m[s.substr(left,l)]!=0)
                        left+=l;
                    left+=l;
                }
                // cout<<left<<' '<<right<<endl;
                right+=l;
            }
            if(right-left==l*len)
                res.push_back(left);
            while(left<n-l+1 && ++m[s.substr(left,l)]!=0)
                left+=l;
            
        }
        
        return res;
    }
};