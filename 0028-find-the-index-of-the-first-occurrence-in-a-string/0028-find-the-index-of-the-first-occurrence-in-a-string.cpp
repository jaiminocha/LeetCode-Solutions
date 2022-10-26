class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        
        for (int i = 0; i < n; i++){
            char ch = haystack[i];
            if (ch == needle[0]){
                int j = 0, k = i;
                for (j = 0; j < needle.size(); j++){
                    if (needle[j] != haystack[k++]){
                        break;
                    }
                }
                if (j == needle.size()) return i;
            }
        }
        return -1;
    }
};