class Solution {
public:
    bool validUtf8(vector<int>& data) {
        unordered_map<int, int> m;
        m[1] = 1;
        m[2] = 192;
        m[3] = 224;
        m[4] = 248;
        
        int n = data.size();
        for (int i = 0; i < n; i++){
            // cout << "Here\n";
            if ((data[i] & m[4]) == 240){
                // cout << 4 << "\n";
                if (i < n - 3 && (data[++i] & 128) == 128 && (data[++i] & 128) == 128 && (data[++i] & 128) == 128) {
                // cout << i << " daring\n";
                if (i == n - 1) return true;
                continue;
            }
                else return false;
            }
            else if ((data[i] & m[3]) == m[3]){
                // cout << 3 << "\n";
                if (i < n - 2 && (data[++i] & 128) == 128 && (data[++i] & 128) == 128){
                    continue;
                }
                else return false;
            }
            else if ((data[i] & m[2]) == m[2]){
                // cout << 2 << "\n";
                if (i < n - 1 && (data[++i] & 128) == 128) {
                    continue;
                }
                else return false;
            }
            else if ((data[i] & 128) == 0){
                // cout << 1 << "\n";
                continue;
            }
            else return false;
        }
        return true;
    }
};