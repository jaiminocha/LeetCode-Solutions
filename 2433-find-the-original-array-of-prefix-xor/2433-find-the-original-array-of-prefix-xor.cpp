class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int prev = 0;
        for (int i = 0; i < pref.size(); i++){
            pref[i] = pref[i] ^ prev;
            prev ^= pref[i];
        }
        return pref;
    }
};