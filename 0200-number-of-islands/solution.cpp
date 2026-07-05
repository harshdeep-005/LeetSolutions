class Solution {
public:
    int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
    int  m,n;
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        m=grid.size(), n=grid[0].size();
        for(int r=0; r<m; r++){
            for(int c=0;c<n; c++){
                if(grid[r][c]=='1'){
                foo(grid, r,c);
                ans++;
                }
            }

        }
        return ans;
    }
    void foo(vector<vector<char>>& grid,int r, int c){
        if(r<0 || c<0 || r>=m ||c>=n || grid[r][c]=='0')return;
        grid[r][c]='0';
        for(int i=0;i<4;i++){foo(grid, r+dr[i], c+dc[i]);}
    }
};
