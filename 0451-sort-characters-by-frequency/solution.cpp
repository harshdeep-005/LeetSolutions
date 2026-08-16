class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        priority_queue<pair<int, char>> pq;

        for (auto p : mp)
            pq.push({p.second, p.first});

        string ans;

        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();

            ans += string(freq, ch);
        }

        return ans;
    }
};
