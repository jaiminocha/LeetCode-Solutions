class Solution {
public:
    bool static comparator(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comparator);
        // for (auto x : properties){
        //     cout << x[0] << " " << x[1] << endl;
        // }
        int maxDef = -1, weak = 0;
        
        for (auto c : properties){
            if (c[1] > maxDef){
                maxDef = c[1];
            }
            else if(c[1] < maxDef) {
                ++weak;
            }
        }
        
        return weak;
    }
};