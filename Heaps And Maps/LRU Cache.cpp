map<int,pair<int,int> > kval;
map<int,int> ts;
int times,cap;
LRUCache::LRUCache(int capacity) {
    times = 0;
    cap = capacity;
    kval.clear();
    ts.clear();
}

int LRUCache::get(int key) {
    times++;
    if(kval.find(key)==kval.end())
    return -1;
    int t = kval[key].second;
    kval[key].second = times;
    int k = ts[t];
    ts.erase(t);
    ts[times] = k;
    return kval[key].first;
}

void LRUCache::set(int key, int value) {
    times++;
    if(kval.find(key)!=kval.end())
    {
        int t2 = kval[key].second;
        kval.erase(key);
        ts.erase(t2);
    }
    else
    {
        if(kval.size()==cap)
        {
            int k = (ts.begin())->first;
            k = ts[k];
            int t2 = kval[k].second;
            kval.erase(k);
            ts.erase(t2);
        }
    }
    kval[key] = make_pair(value,times);
    ts[times] = key;
}
