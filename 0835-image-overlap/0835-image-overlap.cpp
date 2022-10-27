class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int> > ones1, ones2;
            
        int n = img1.size();
        map<pair<int, int>, int> m2, m1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (img1[i][j]){
                    ones1.push_back({i, j});
                    m1[{i, j}] = img1[i][j];
                }
                if (img2[i][j]){
                    ones2.push_back({i, j});
                    m2[{i, j}] = img2[i][j];
                }
            }
        }
        if (ones1.size() == 0) return 0;
        if (ones2.size() == 0) return 0;
        int counter = 0;
        
        // for (auto [x2, y2] : ones2){
        //     int count = 1;
        //     int i = ones1[0].first;
        //     int j = ones1[0].first;
        //     int shiftx = x2 - i;
        //     int shifty = y2 - j;
        //     for (int i = 1; i < ones1.size(); i++){
        //         int x1 = ones1[i].first + shiftx;
        //         int y1 = ones1[i].second + shifty;
        //         if (m2.count({x1, y1})){
        //             count++;
        //         }
        //     }
        //     counter = max(counter, count);
        // }
        map<pair<int, int>, int> m;
        for (auto [x1, y1] : ones1){
            for (auto [x2, y2] : ones2){
                m[{x2 - x1, y2 - y1}]++;
                counter = max(counter, m[{x2 - x1, y2 - y1}]);
            }
        }
        
        return counter;
    }
    
};