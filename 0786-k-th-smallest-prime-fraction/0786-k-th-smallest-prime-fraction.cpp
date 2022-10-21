typedef pair<double, pair<int, int> > node;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<node, vector<node>, greater<node> > pq;
        
        int n = arr.size();
        for (int i = 0; i < n; i++){
            double num = arr[i];
            for (int j = i + 1; j < n; j++){
                double denom = arr[j];
                double frac = (num / (denom * 1.0));
                pq.push({frac, {num, denom}});
            }
        }
        int num = -1, denom = -1;
        while (k--){
            num = pq.top().second.first;
            denom = pq.top().second.second;
            //cout << num << "," << denom << endl;
            pq.pop();
        }
        return {num, denom};
    }
};