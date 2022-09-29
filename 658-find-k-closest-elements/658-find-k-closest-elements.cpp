class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int> > pq;
        int n = arr.size();
        vector<int> ans(k);
        for (int i = 0; i < n; i++){
            int diff = abs(arr[i] - x);
            if (pq.size() < k){
                pq.push({diff, arr[i]});
            }
            else if (pq.top().first > diff){
                pq.pop();
                pq.push({diff, arr[i]});
            }
            else if (pq.top().first == diff && pq.top().second > arr[i]){
                pq.pop();
                pq.push({diff, arr[i]});
            }
        }
        for (int i = 0; i < k; i++){
            ans[i] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};