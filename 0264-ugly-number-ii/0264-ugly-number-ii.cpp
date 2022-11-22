class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        if (n == 1) return 1;
        pq.push(1);
        vector<int> dict{2,3,5};
        int i = 1;
        unordered_set<long long int> s;
        s.insert(1);
        while (!pq.empty()){
            long long int top = pq.top();
            pq.pop();
            //cout << top << " ";
            for (auto x : dict) {
                long long val = x * top;
                if (s.find(val) == s.end()){             
                    pq.push(val);   
                    s.insert(val);
                }
            }
            if (i == n) return top;
            i++;
        }
        return -1;
    }
};