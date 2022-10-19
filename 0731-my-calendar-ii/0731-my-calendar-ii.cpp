class MyCalendarTwo {
public:
    map<int, int> m;  // ((start, end) , count)
    map<int, int> trip;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto x : trip){
            if (start < x.second && end > x.first){
                return false;
            }
        }
        for (auto x : m){
            if (start < x.second && end > x.first){
                int s = max(x.first, start);
                int e = min(x.second, end);
                trip[s] = e;
            }
        }
        if (m.count(start)) end = max(end, m[start]);
        m[start] = end;
        return true;
    }
};

/*
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */