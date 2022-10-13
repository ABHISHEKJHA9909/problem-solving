class Solution {
public:
    static bool comp(string &s,string &t){
        int x=s.size()+t.size();
        int i=0,j=0;
        while(x--){
            if(s[i]!=t[j])
                return s[i]>t[j];
            i++,j++;
            if(i==s.size())
                i=0;
            if(j==t.size())
                j=0;
        }
        return 0;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int i:nums){
            arr.push_back(to_string(i));
        }
        
        sort(arr.begin(),arr.end(),comp);
        
        string s="";
        for(string t:arr)
            s+=t;
        if(s[0]=='0')
            return "0";
        
        return s;
    }
};