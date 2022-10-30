int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
typedef pair<int, pair<int, int> > node;
class Solution {
public:
    int solve(vector<vector<int>>& grid,int k){
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
	
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
			
			// Exit if current position is outside of the grid
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
			
			// Destination found
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return t[2];

            if(grid[x][y]==1){
                if(t[3]>0)
                    t[3]--;
                else
                    continue;
            }
			

            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue;
            vis[x][y]=t[3];
            
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
    // int shortestPath(vector<vector<int>>& grid, int k) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<vector<bool>> visited(n, vector<bool> (m, false));
    //     vector<vector<int> > obst(n, vector<bool> (m, 0));
    //     queue<node> q;   // x, y,
    // }
};