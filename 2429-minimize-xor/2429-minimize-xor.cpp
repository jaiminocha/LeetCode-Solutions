class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = num1, n2 = num2;
        
        int bits2 = 0, x = 0;
        while (n2){
            if (n2 & 1) bits2++;
            n2 >>= 1;
        }//cout << bits2 << endl;
        
        string s1;
        while (n1){
            if (n1 & 1) s1.push_back('1');
            else s1.push_back('0');
            n1 >>= 1;
        }
        // reverse(s1.begin(), s1.end());
        vector<int> bitsX;
        for (int i = s1.size(); i >= 0; i--){
            if (s1[i] == '1'){
                if (bits2 > 0) {
                    bits2--;
                    bitsX.push_back(1);
                }
                else bitsX.push_back(0);
            }
            else bitsX.push_back(0);
        }
        reverse(bitsX.begin(), bitsX.end());
        // cout << "\nbitsX: ";
        // for (auto x : bitsX) cout << x << " ";
        // cout << endl;
        // cout << "bits2 " << bits2 << endl;
        if (bits2 > 0){
            for (int i = 0; i < bitsX.size(); i++){
                if (bitsX[i] == 1) continue;
                bits2--;
                bitsX[i] = 1;
                if (bits2 == 0) break;
            }
            while (bits2--){
                bitsX.push_back(1);
            }
        }
        
        int ans = 0, k = 0;
        for (int i = 0; i < bitsX.size(); i++){
            //cout << bitsX[i] << " ";
            ans += (bitsX[i] * pow(2, k));
            k++;
        }
        return ans;
    }
};