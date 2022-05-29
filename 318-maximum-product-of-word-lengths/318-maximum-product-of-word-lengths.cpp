class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>arr(words.size(),0);     //array to store string charcter set
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                arr[i]|=(1<<(words[i][j]-'a'));      //setting char position as 1
            }
        }
        
        int res=0;
        
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if((arr[i]&arr[j])==0){       //if no element common
                    res=max(res,(int)(words[i].size()*words[j].size()));     //find max ans
                }
            }
        }
        
        return res;
    }
};