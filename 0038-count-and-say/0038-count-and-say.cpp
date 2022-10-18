class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        int i = 1;
        while (i < n){
            int size = ans.size();
            string temp = ans;
            ans = "";
            int j = 0;
            while (j < size){
                int count = 0;
                char ch = temp[j];
                while (j < size && ch == temp[j]){
                    count++;
                    j++;
                }
                ans += (to_string(count) + ch);
            }
            
            i++;
        }
        return ans;
    }
};