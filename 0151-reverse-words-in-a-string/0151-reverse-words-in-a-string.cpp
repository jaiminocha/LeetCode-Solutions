class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 1) return s;
        if (s[0] == ' ' || s[n - 1] == ' '){
            int i = 0;
            while (s[i] == ' '){
                i++;
            }
            int j = n - 1;
            while (s[j] == ' '){
                j--;
            }
            j -= i;
            j++;
            s = s.substr(i, j);
        }
        // cout << "'" << s << "'" << endl;
        stack<string> st;
        string temp;
        for (int i = 0; i <= n; i++){
            if (s[i] == ' ' || s[i] == '\0'){
                cout << "temp: " << "'" << temp << "'" << endl;
                if (!temp.empty()) st.push(temp);
                temp = "";
                if (s[i] == '\0') break;
            }
            else temp.push_back(s[i]);
        }
        s = "";
        while (!st.empty()){
            s += st.top();
            if (st.size() != 1) s += ' ';
            st.pop();
        }
        return s;
    }
};