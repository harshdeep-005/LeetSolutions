class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& x) {
        sort(x.begin(),x.end());
        int i;
        long sum=mass;
        for( i=0; i<x.size(); i++){
            if(sum>=x[i])sum+=x[i];
            else break;
        }
        if(i==x.size())return true;
        return false;

    }
};
