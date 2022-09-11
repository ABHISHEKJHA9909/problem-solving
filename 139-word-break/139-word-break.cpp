class Solution {
public:
    unordered_map<string,bool>m;
    
    bool wordBreak(string s, vector<string>& arr) {
        if(find(arr.begin(),arr.end(),s)!=arr.end())
            return true;
        if(m.find(s)!=m.end())
            return m[s];
        for(int i=1,n=s.size();i<n;i++){
            if(find(arr.begin(),arr.end(),s.substr(0,i))!=arr.end() && wordBreak(s.substr(i),arr)){
                m[s.substr(0,i)]=true;
                return true;
            }
        }
        return m[s]=false;
    }
};