class Solution {
public:
    string get(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        for(int i=1;i<=1e9;i*=2){
            if(get(i)==get(n))
                return true;
        }
        return false;
    }
};