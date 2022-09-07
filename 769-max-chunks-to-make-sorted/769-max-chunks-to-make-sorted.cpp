class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxYet = arr[0], ans = 0;
        int n = arr.size();
        if (n == 1) return 1;
        for (int i = 0; i < n; i++){
            maxYet = max(maxYet, arr[i]);
            // cout << arr[i] << ", " << i << endl;
            if (maxYet == i){
                // cout << "match: " << arr[i] << ", " << i << endl;
                ans++;
                if (i + 1 < n) maxYet = arr[i + 1];
            }
        }
        return ans;
    }
};