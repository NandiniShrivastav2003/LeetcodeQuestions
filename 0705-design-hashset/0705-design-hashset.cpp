class MyHashSet {
public:
    vector<list<int>>m;
    int siz;
    MyHashSet() {
        siz=100;
        m.resize(siz);
    }
    
    void add(int key) {
        if(contains(key)){
            return ;
        }
        int i=hash(key);
        m[i].push_back(key);
    }
    int hash(int key){
        return key%siz;
    }
    list<int>::iterator search(int key){
        int i=hash(key);
        return find(m[i].begin(),m[i].end(),key);
    }
    void remove(int key) {
        if(!contains(key)){
            return ;
        }
        int i=hash(key);
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key) == m[i].end()){
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */