class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        stack<pair<int,int>> st;
        int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};
        int col=image[sr][sc],m=image.size(),n=image[0].size();
        st.push({sr,sc});
        while(!st.empty()){
            int r=st.top().first,c=st.top().second;
            st.pop();
            image[r][c]=color;
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n&& image[nr][nc]==col )st.push({nr,nc});
            }
        }
        return image;
    }
};
