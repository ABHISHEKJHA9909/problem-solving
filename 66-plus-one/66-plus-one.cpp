class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int c=1;
        
        for(int i=digits.size()-1;i>=0;i--){
            int x=digits[i]+c;
            int y=x%10;
            c=x/10;
            res.push_back(y);
        }
        if(c)
            res.push_back(c);
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};