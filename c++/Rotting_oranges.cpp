class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        int c=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>v(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    v[i][j]=1;
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        
        int time=0;
        vector<int>row = {-1, 0, +1, 0};
        vector<int>col = {0, 1, 0, -1}; 
        
        while(!q.empty())
        {
            int f=q.front().first.first;
            int g=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            // cout<<f<<" "<<g<<" "<<t<<endl;
            q.pop();
            
            for(int i=0;i<row.size();i++)
            {
                int nrow = f + row[i];
                int ncol = g + col[i];
                // check for valid cell and 
                // then for unvisited fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                  v[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                  // push in queue with timer increased
                   q.push({{nrow, ncol}, t + 1}); 
                  // mark as rotten
                  v[nrow][ncol] = 1;
                  fresh--;
                }
            }
        }
        return fresh==0?time:-1;
    }
};
