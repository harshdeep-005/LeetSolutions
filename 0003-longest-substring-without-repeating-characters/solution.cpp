class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
        cout << "0" << endl;
        return 0;
    }

    int maxSize = 0;
    int start = 0;
    unordered_set<char> seenChars;

    for (int end = 0; end < s.size(); end++) {
        while (seenChars.find(s[end]) != seenChars.end()) {
            seenChars.erase(s[start]);
            start++;
        }
        seenChars.insert(s[end]);
        maxSize = max(maxSize, end - start + 1);
    }
        return maxSize;
    }
};
