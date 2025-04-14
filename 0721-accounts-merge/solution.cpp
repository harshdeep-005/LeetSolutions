class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> emailToName;

        function<string(string)> find = [&](string s) {
            if (parent[s] != s)
                parent[s] = find(parent[s]);
            return parent[s];
        };

        auto unite = [&](string a, string b) {
            parent[find(a)] = find(b);
        };

        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                emailToName[email] = name;
                if (parent.find(email) == parent.end())
                    parent[email] = email;
                if (i > 1)
                    unite(account[i], account[i - 1]);
            }
        }

        unordered_map<string, set<string>> unions;
        for (auto& [email, _] : emailToName) {
            string root = find(email);
            unions[root].insert(email);
        }

        vector<vector<string>> res;
        for (auto& [root, emails] : unions) {
            vector<string> group{emailToName[root]};
            group.insert(group.end(), emails.begin(), emails.end());
            res.push_back(group);
        }

        return res;
    }
};

