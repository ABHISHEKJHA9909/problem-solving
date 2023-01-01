class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>arr;
        while(ss>>s){
            arr.push_back(s);
        }
        
        if(arr.size()!=pattern.size())
            return false;
        
        unordered_map<char,string>cs;
        unordered_map<string,char>sc;
        
        for(int i=0;i<arr.size();i++){
            if(cs.find(pattern[i])!=cs.end() && cs[pattern[i]]!=arr[i])
                return false;
            if(sc.find(arr[i])!=sc.end() && sc[arr[i]]!=pattern[i])
                return false;
            cs[pattern[i]]=arr[i];
            sc[arr[i]]=pattern[i];
        }
        
        return true;
    }
};