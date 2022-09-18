class Solution {
public:
    int trap(vector<int>& h) {
        // int n = height.size();
        // int left[n];
        // int right[n];
        // left[0] = height[0];
        // right[n - 1] = height[n - 1];
        // for (int i = 1; i < n; i++){
        //     left[i] = max(left[i - 1], height[i]);
        // }
        // for (int i = n - 2; i >= 0; i--){
        //     right[i] = max(right[i + 1], height[i]);
        // }
        // int vol = 0;
        // for (int i = 0; i < n; i++){
        //     vol += min(left[i], right[i]) - height[i];
        // }
        // return vol;
        
        int water = 0, l = 0, r = h.size()-1, lmax = INT_MIN, rmax = INT_MIN;
        while(l < r){
            lmax = max(h[l], lmax);
            rmax = max(h[r], rmax);
            water += (lmax < rmax) ? lmax-h[l++] : rmax-h[r--] ;
        }
        return water;
    }
};