class Solution {
public:
    int max(int a, int b){if(a>b)return a; else return b;}
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        int m= tasks.size();
        int maxi=0;
        for (char task : tasks) {
            freq[task]++;
            maxi=max(maxi, freq[task]);
        }
        int total=(maxi-1)*(n+1);
        sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
        for(auto pair:freq)if(pair.second==maxi)total++;
        maxi=max(total,tasks.size());
        return maxi;
    }
};
