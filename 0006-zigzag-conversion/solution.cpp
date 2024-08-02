class Solution {
public:
    string convert(string s, int n) {    

    string arr[n]; 
    int j = 0;
    while (j < s.size()) {
        for (int i = 0; i < n && j < s.size(); i++) {
            arr[i].push_back(s[j]);
            j++;
        }

        for (int i = n - 2; i > 0 && j < s.size(); i--) {
            arr[i].push_back(s[j]);
            j++;
        }
    }

    string S;
    for (int i = 0; i < n; i++) {
        S += arr[i];
    }
    return S;
    }
};
