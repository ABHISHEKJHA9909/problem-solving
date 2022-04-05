class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        
        int res=0;
        while(i<j){
            res=max(res,min(arr[i],arr[j])*(j-i));
            if(arr[i]<arr[j])
                i++;
            else
                j--;
        }
        return res;
    }
};