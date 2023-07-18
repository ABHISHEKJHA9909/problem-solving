class node{
    public:
    node *prev=NULL;
    int key;
    int val;
    node *next=NULL;
    
    node(int key,int val){
        this->key=key;
        this->val=val;
    }
};

class LRUCache {
public:
    int cap;
    map<int,node*>m;
    node *first=NULL,*last=NULL;
    
    node* insert(int key,int val){
        node * newNode=new node(key,val);
        if(first==NULL){
            first=last=newNode;
        }
        else{
            newNode->next=first;
            first->prev=newNode;
            first=newNode;
        }
        if(--cap==-1){
            node* curr=remove(last);
            m[curr->key]=NULL;
        }
        return newNode;
    }
    
    node* remove(node* n){
        cap++;
        node* curr=n;
        if(curr->prev){
            curr->prev->next=curr->next;
        }
        else{
            first=curr->next;
        }
        if(n->next){
            curr->next->prev=curr->prev;
        }
        else{
            last=curr->prev;
        }
        return curr;
    }
    
    LRUCache(int capacity) {
        this->cap=capacity;
    }
    
    int get(int key) {
        if(m[key]){
            node *curr=remove(m[key]);
            m[key]=insert(curr->key,curr->val);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m[key])
            remove(m[key]);
        m[key]=insert(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */