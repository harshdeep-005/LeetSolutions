class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> a;
        int i = 0;
        string b = "", d = "";
        char c;
        while (s[i]) {
            c = s[i];
            if (((int)c >= 48 && (int)c <= 57) ||((int)c >= 65 && (int)c <= 90) ||((int)c >= 97 && (int)c <= 122)) {
                a.push(c);
                b += c;
            }
            i++; 
        }
        while (!a.empty()) {
            d += a.top();
            a.pop();
        }
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        transform(d.begin(), d.end(), d.begin(), ::tolower);
        cout<<"b : "<<b<<endl;
        cout<<"d : "<<d<<endl;
        if (b == d) return true;
        else return false; 
    }
};
