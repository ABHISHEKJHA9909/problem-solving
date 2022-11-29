
class RandomizedSet {
private:
    vector<int>arr;
    unordered_map<int,int>m;
    
public:
    RandomizedSet(){
        srand(time(0));
    };
    
    bool insert(int val) {
        if(m[val])
            return false;
        arr.push_back(val);
        m[val]=arr.size();
        return true;
    }
    
    bool remove(int val) {
        if(m[val]){
            m[arr.back()]=m[val];
            swap(arr[m[val]-1],arr[arr.size()-1]);
            m[val]=0;
            arr.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */