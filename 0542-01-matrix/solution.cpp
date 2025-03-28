// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         vector<vector<int>> arr(mat);
//         int m = mat.size(), n = mat[0].size();
//         queue<pair<int, int>> q;
//         bool found = false;

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == 1) {
//                     q.push({i, j});
//                     arr[i][j]=-1;
//                     found = true;
//                     break; 
//                 }
//             }
//             if (found) break;
//         }
//         int dx[4] = {0, 0, 1, -1};
//         int dy[4] = {1, -1, 0, 0};
//         while(!q.empty()){
//             int a=q.front().first, b=q.front().second;
//             q.pop();
//             bool x=false, y=false;
//             int lov=10001;
//             for(int i=0; i<4; i++){
//                 int nsr=a+dx[i], nsc=b+dy[i];
//                 if(nsr < 0 || nsc < 0 || nsr >= m || nsc >= n || mat[nsr][nsc] == 1 || arr[a][b]==-1)continue;         
//                 if(mat[nsr][nsc]==0)x=true;
//                 if(mat[nsr][nsc]==1)y=true;
//                 lov=min(lov,mat[nsr][nsc]);
//                 if(arr[nsr][nsc]!=-1){
//                     q.push({nsr,nsc});
//                     arr[nsr][nsc]=-1;
//                 }
//             }
//             if(!x){
//                 mat[a][b]+=lov;
//                 if(!y)q.push({a,b});
//             }
//         }
//         return mat;
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1)); 
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int a = q.front().first, b = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nsr = a + dx[i], nsc = b + dy[i];

                if (nsr < 0 || nsc < 0 || nsr >= m || nsc >= n || dist[nsr][nsc] != -1) 
                    continue;

                dist[nsr][nsc] = dist[a][b] + 1; 
                q.push({nsr, nsc});
            }
        }

        return dist;
    }
};

