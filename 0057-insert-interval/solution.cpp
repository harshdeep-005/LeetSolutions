class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& y, vector<int>& n) {
        vector<vector<int>> ans;
        sort(y.begin(), y.end());
        int m=y.size(), i=0;
        while(i<m && n[0]>y[i][1]){
            ans.push_back(y[i]);
            i++;
        }
        while(i<m && n[1]>=y[i][0]){
            n[0]=min(n[0],y[i][0]);
            n[1]=max(n[1],y[i][1]);
            i++;
        }
        ans.push_back(n);
        while(i<m ){
            ans.push_back(y[i]);
            i++;
        }
        return ans;
    }
};
