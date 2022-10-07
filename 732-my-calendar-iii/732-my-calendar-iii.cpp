class MyCalendarThree {
public:
    map<int , int> mp ;
    MyCalendarThree() {
        
    }
    
    int book(int st , int end) {
        int ans=0 , ct=0 ;
        mp[st]++ ;
        mp[end]-- ;
        for(auto &it : mp)
        {
            ct += it.second ;
            ans = max(ans , ct) ;
        }
        return ans ;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */