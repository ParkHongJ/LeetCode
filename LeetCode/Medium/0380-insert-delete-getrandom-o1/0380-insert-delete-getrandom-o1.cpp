class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(nullptr));
        m.reserve(5000000);
    }
    
    bool insert(int val) {
        if (m.find(val) == m.end())
        {
            d.push_back(val);
            m.insert( {val, d.size() - 1} );
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end())
        {
            return false;
        }

        int eraseIdx = m[val];
        if (d[eraseIdx] == d[d.size() - 1])
        {
            d.pop_back();
        }
        else
        {
            d[eraseIdx] = d[d.size() - 1];
            
            int tempval = d[eraseIdx];

            m[tempval] = eraseIdx;
        }
        m.erase(val);

        return true;
    }
    
    int getRandom() {
        int idx = rand() % d.size();
        return d[idx];
    }
    unordered_map<int,int> m;
    deque<int> d;
        
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */