class Solution {
public:
    void foo(string num, vector<string>& log, vector<string>& x, string& st) {
        if (num.empty()) { 
            for (int i = 0; i < st.length(); i++)st[i] = tolower(st[i]);
            x.push_back(st); 
            return; 
        }
        
        int index = num[0] - '2'; 
        for (char c : log[index]) { 
            st.push_back(c);
            foo(num.substr(1), log, x, st);
            st.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Edge case: Empty input

        vector<string> log{"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}; 
        vector<string> x;
        string st;
        foo(digits, log, x, st);
        return x;
    }
};

