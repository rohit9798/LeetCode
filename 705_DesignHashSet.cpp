Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)



class MyHashSet {
public:
    /** Initialize your data structure here. */
    int capacity;
    float loadFactor;
    vector<vector<int>> bucket;
    int size;
    
    MyHashSet() {
        
        capacity = 100;
        loadFactor = .75f;
        size = 0;
        vector<vector<int>> temp(capacity);
        bucket = temp;
        
    }
    
    void add(int key) {
        
        if(contains(key))
            return;
        if(loadFactor * capacity == size)
        {
            size = 0;
            capacity = capacity * 2;
            vector<vector<int>> oldBucket = bucket;
            vector<vector<int>> temp(capacity);
            bucket = temp;
            for(int i = 0; i < oldBucket.size(); i++)
            {
                if(oldBucket[i].size() > 0)
                {
                    for(int j = 0 ; j < oldBucket[i].size(); j++)
                        this -> add(oldBucket[i][j]);
                }
            }
        }
        int hash = key % capacity;
        bucket[hash].push_back(key);
        size++;
    }
    
    void remove(int key) {
        
        int hash = key % capacity;
        for(int i = 0; i < bucket[hash].size(); i++)
        {
            if(bucket[hash][i] == key)
            {
                bucket[hash].erase(bucket[hash].begin() + i);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
        int hash = key % capacity;
        for(int i = 0; i < bucket[hash].size(); i++)
        {
            if(bucket[hash][i] == key)
            {
                return true;
            }
        }
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
