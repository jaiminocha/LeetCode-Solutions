class TimeMap {
public:
    unordered_map<string, priority_queue<pair<int, string> > > m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.count(key)){
            int ts = m[key].top().first;
            if (ts <= timestamp){
                return m[key].top().second;
            }
            vector<pair<int, string> > v;
            while (!m[key].empty()){
                pair<int, string> p = m[key].top();
                m[key].pop();
                v.push_back(p);
                if (p.first <= timestamp){
                    for (auto x : v){
                        m[key].push(x);
                    }
                    return p.second;
                }
            }
            for (auto x : v){
                m[key].push(x);
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */