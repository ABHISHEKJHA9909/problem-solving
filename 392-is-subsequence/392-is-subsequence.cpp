class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it1=s.begin() ,it2=t.begin();
        
        while(it1!=s.end() && it2!=t.end()){
            if(*it1==*it2)
                ++it1;
            ++it2;
        }
        
        return it1==s.end();
    }
};