class MyHashSet {
public:
    vector < int> m;
    MyHashSet() 
    {
        for (int i=0;i <=1000001;i++)
            m.push_back(0);
    }
    
    void add(int key) 
    {
        m[key] =1;
    }
    
    void remove(int key) 
    {
        m[key] = 0;
    }
    
    bool contains(int key) 
    {
        if(m[key])
        {
            return true;
        }
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */