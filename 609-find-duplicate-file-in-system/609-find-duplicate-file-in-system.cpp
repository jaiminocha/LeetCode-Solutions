class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        vector<vector<string> > ans;
        unordered_map<string, vector<string> > m;
        
        for (string path : paths){
            vector<string> fileName;
            vector<string> content;
            string fullPath;
            bool space = false;
            for (int i = 0; i < path.size(); i++){
                if (path[i] == ' ') space = true;
                if (!space){
                    fullPath.push_back(path[i]);
                }
                else {
                    int j = i + 1;
                    string fn;
                    bool brac = false;
                    for (; j < path.size(); j++){
                        if (path[j] == '(') brac = true;
                        if (brac){
                            fileName.push_back(fn);
                            fn = "";
                            int k = j + 1;
                            string ct;
                            for (; k < path.size() && path[k] != ')'; k++){
                                ct.push_back(path[k]);
                            }
                            content.push_back(ct);
                            j = k + 1;
                            brac = false;
                        }
                        else fn.push_back(path[j]);
                    }
                    i = j;
                }
            }
            fullPath.push_back('/');
            int sz = fileName.size();
            for (int j = 0; j < sz; j++){
                m[content[j]].push_back(fullPath + fileName[j]);
            }
        }
        for (auto x : m){
            if (x.second.size() > 1){
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};