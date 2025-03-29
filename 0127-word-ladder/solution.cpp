class Solution {
public:
    int ladderLength(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(),bank.end());
        if(!bankset.count(end))return 0;
        queue<pair<string,int>>q;
        q.push({start, 1});
        unordered_set<char>gens;
        for(int i=0;i<bank.size(); i++){
            for(auto s:bank[i]){
                gens.insert(s);
            }
        }
        while(!q.empty()){
            auto[current, steps]=q.front();
            q.pop();
            if(current==end)return steps;
            for(int i=0; i<8; i++){
                char org=current[i];
                for(auto g:gens){
                    if(g==org)continue;
                    current[i]=g;
                    if(bankset.count(current)){
                        q.push({current,steps+1});
                        bankset.erase(current);
                    }
                }
                current[i]=org;
            }
        }
        return 0;
    }
};
