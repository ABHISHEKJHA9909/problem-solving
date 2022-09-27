class Solution {
public:
    string pushDominoes(string s) {
        vector<int>arr;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='.')
                arr.push_back(i);
        }
        
        for(int i=0;i<arr.size();i++){
            if(s[arr[i]]=='L'){
                int j=arr[i]-1;
                while(j>=0 && s[j]=='.'){
                    s[j]='L';
                    j--;
                }
            }
            else if(i+1<arr.size() && s[arr[i+1]]=='L'){
                int j=arr[i]+1;
                int k=arr[i+1]-1;
                while(j<k){
                    s[j]='R';
                    s[k]='L';
                    j++,k--;
                }
                i++;
            }
            else{
                int j=arr[i]+1;
                while(j<s.size() && s[j]=='.'){
                    s[j]='R';
                    j++;
                }
            }
        }
        
        return s;
    }
};