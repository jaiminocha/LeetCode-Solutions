class SmallestInfiniteSet {
public:
    int smallest;
    set<int> s;
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        // int low = INT_MAX;
        // for (auto x : s){
        //     low = x;
        //     break;
        // }
        // if (low < smallest){
        //     s.erase(low);
        //     return low;
        // }
        if (!s.empty()){
            int low = *begin(s);
            s.erase(low);
            return low;
        }
        return smallest++;
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