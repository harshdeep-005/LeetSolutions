class Solution {
public:
    string sortSentence(string s) {
        vector<string> a(9);
        
        int i = 0;
        int l = 0;

        while (i < s.length()) {
            if (s[i] == ' ') {
                l = i + 1;
            }
            
            if (s[i] >= '1' && s[i] <= '9') {
                int pos = s[i] - '1';

                // word starts at l
                // digit is at i
                a[pos] = s.substr(l, i - l);
            }

            i++;
        }

        string ans = "";

        for (int i = 0; i < 9; i++) {
            if (a[i].empty())
                break;

            if (!ans.empty())
                ans += " ";

            ans += a[i];
        }

        return ans;
    }
};
