class Graph{
    int V;
    list<pair<int, int> > l;
public:
    Graph(int v){
        V = v;
    }
    void addEdge(int node1, int node2){
        l.push_back({node1, node2});
    }
    void displayEdges(){
        for (auto x : l){
            cout << x.first << " " << x.second << endl;
        }
    }
    int findSet(int i, vector<int> &parent){
        if (parent[i] == -1){
            return i;
        }
        return parent[i] = findSet(parent[i], parent);
    }
    void doUnion(int node1, int node2, vector<int> &parent){
        int s1 = findSet(node1, parent);
        int s2 = findSet(node2, parent);
        
        if (s1 != s2){
            parent[s1] = s2;
        }
    }
    
    bool containsCycle(vector<pair<int, int> > &neq){
        vector<int> parent(V, -1);
        // cout << "size: " << V << endl;
        for (auto x : l){
            int node1 = x.first;
            int node2 = x.second;
            
            int s1 = findSet(node1, parent);
            int s2 = findSet(node2, parent);
            
            if (s1 != s2){
                doUnion(s1, s2, parent);
            }
        }
        for (auto x : neq){
            int node1 = x.first;
            int node2 = x.second;
            // cout << node1 << " " << node2 << endl;
            int s1 = findSet(node1, parent);
            int s2 = findSet(node2, parent);
            // cout << node1 << ", " << s1 << endl;
            // cout << node2 << ", " << s2 << endl;
            if (s1 == s2) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<pair<int, int> > neq;
        Graph g(26);
        for (auto x : equations){
            int num1 = x[0] - 'a', num2 = x[3] - 'a';  
            // cout << "Numbers: " << num1 << " " << num2 << "\n";
            if (num1 == num2) {
                if (x[1] == '!') return false;
                continue;
            }
            if (x[1] == '!') neq.push_back({num1, num2});
            else g.addEdge(num1, num2);
        }
        // g.displayEdges();
        return !(g.containsCycle(neq));
    }
};