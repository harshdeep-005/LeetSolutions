class Solution {
public:
    int square(int a){return a*a;}
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        int n=p.size(),temp;
        for(int i=0;i<n;i++){
            temp=square(p[i][0])+square(p[i][1]);
            pq.push({temp,i});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int a=pq.top().second;
            ans.push_back({p[a][0],p[a][1]});
            pq.pop();
        }
        return ans;
    }
};
