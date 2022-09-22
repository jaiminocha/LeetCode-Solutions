class Solution {
public:
    
//     void reversePart(string &s, int i, int j){
//         while (i < j){
//             swap(s[i++], s[j--]);
//         }
//         // cout << s << "\n";
//     }
    
//     string reverseWords(string s) {
//         int l = 0, r = 0;
//         for (int i = 0; i < s.size(); i++){
//             if (s[i] == ' '){
//                 // cout << "i: " << i << "\n";
//                 r = i - 1;
//                 reversePart(s, l, r);
//                 l = i + 1;
//             }
//         }
//         reversePart(s, l, s.size() - 1);
//         return s;
//     }
    void reverseString(string &s, int l, int r){
        while (l < r){
            swap(s[l++], s[r--]);
        }
    }
    string reverseWords(string s) {
        int n = s.length();

        int l = 0, r = 0;
        for (int i = 0; i < n ; i++){
            if (s[i] == ' '){
                reverseString(s, l, r - 1);
                l = r + 1;
            }
            else if (i == n - 1){
                reverseString(s, l, r);
            }
            r++;
        }
        return s;
    }
};