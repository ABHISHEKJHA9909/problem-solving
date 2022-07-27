class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int>s;
        int l=1;
        for(int i:rolls){
            s.insert(i);
            if(s.size()==k){
                s.clear();
                l++;
            }
        }
        return l;
    }
};