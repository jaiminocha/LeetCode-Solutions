class SmallestInfiniteSet {
public:
    int smallest;
    set<int> s;
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        int low = INT_MAX;
        for (auto x : s){
            low = x;
            break;
        }
        if (low < smallest){
            s.erase(low);
            return low;
        }
        smallest++;
        return smallest - 1;
    }
    
    void addBack(int num) {
        if (num < smallest){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */