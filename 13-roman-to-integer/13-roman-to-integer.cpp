class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int sum=m[s.back()];
        int i=s.size()-2;
        while(i>=0){
            sum+=m[s[i]];
            if(m[s[i]]<m[s[i+1]])
                sum-=2*m[s[i]];
            i--;
        }
        return sum;
    }
};