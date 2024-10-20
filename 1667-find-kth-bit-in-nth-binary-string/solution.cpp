class Solution {
public:
    string invert(string s) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if(s[i] == '0') s[i]='1';
            else s[i]='0';
        }
        return s;
    }

    string reverse(string s) {
        stack<char> a;
        for (char c : s) {
            a.push(c);
        }
        string reversed;
        while (!a.empty()) {
            reversed += a.top();
            a.pop();
        }
        return reversed;
    }

    string newstring(string s, int n) {
        if (n == 1) return s;
        string newS = s + "1" + reverse(invert(s));
        return newstring(newS, n - 1);
    }

    char findKthBit(int n, int k) {
        string s = newstring("0", n);
        return s[k - 1];
    }
};

