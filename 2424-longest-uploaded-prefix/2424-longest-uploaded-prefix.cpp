class LUPrefix {
public:
    int total, longestYet = 0;
    unordered_map<int, bool> m;
    LUPrefix(int n) {
        total = n;
    }
    
    void upload(int video) {
        m[video] = true;
    }
    
    int longest() {
        int i = longestYet + 1;
        while (m.count(i)){
            i++;
        }
        longestYet = i - 1;
        return longestYet;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */