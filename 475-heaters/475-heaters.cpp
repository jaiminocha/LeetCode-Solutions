class Solution {
public:
    int binarySearch(vector<int> &heaters, int size, int pos){
        int s = 0, e = size - 1;
        int minDiff = INT_MAX;
        while (s <= e){
            int mid = s + (e - s) / 2;
            int diff = abs(heaters[mid] - pos);
            minDiff = min(minDiff, diff);
            if (pos == heaters[mid]) return 0;
            if (pos < heaters[mid]){
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return minDiff;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        sort(heaters.begin(), heaters.end());
        int res = INT_MIN;
        for (int i = 0; i < n; i++){
            int h = binarySearch(heaters, m, houses[i]);
            res = max(res, h);
        }
        return res;
    }
};