class Solution {
public:
    string makeGood(string s) {
        string ans;
        int n = s.size();
        if (n == 1) return s;
        stack<char> st;
        for (int i = 0; i < n; i++){
            char ch = s[i];
            char ch1 = s[i] + 32, ch2 = s[i] - 32;
            if (!st.empty() && (st.top() != ch1 && st.top() != ch2)){
                st.push(ch);
            }
            else if(!st.empty() && (st.top() == ch1 || st.top() == ch2)) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};