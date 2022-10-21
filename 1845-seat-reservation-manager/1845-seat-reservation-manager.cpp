class SeatManager {
public:
    int seat, totalSeats;
    set<int> s;
    SeatManager(int n) {
        seat = 1;
        totalSeats = n;
    }
    
    int reserve() {
        if (!s.empty()){
            int unrev = *(begin(s));
            s.erase(unrev);
            return unrev;
        }
        return seat++;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */