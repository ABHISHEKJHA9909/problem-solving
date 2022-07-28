class Solution {
public:
    unordered_map<int,int>m;
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        for(char c:s){
            m[c]++;
        }
        for(char c:t){
            m[c]--;
            if(m[c]==0)
                m.erase(c);
        }
        return m.size()==0;
    }
};