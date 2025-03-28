class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>arr(image);
        int bro=arr[sr][sc];
        if(bro==color)return arr;
        int m=image.size(), n=image[0].size();
        arr[sr][sc]=color;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            int a=q.front().first, b=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nsr=a+dx[i], nsc=b+dy[i];
                if(nsr < 0 || nsc < 0 || nsr >= m || nsc >= n || arr[nsr][nsc] != bro)continue;
                arr[nsr][nsc]=color;
                q.push({nsr,nsc});
            }
        }
        return arr;
    }
};
