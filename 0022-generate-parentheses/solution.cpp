class Solution {
public:
    void foo(vector<string>& sol, string ans, int open, int close) {
        if(open == 0 && close == 0) {
            sol.push_back(ans);
            return;
        }

        if(open > 0) {
            foo(sol, ans + '(', open - 1, close);
        }
        
        if(close > open) {
            foo(sol, ans + ')', open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        foo(sol, "", n, n);
        return sol;
    }
};
