// class Solution {
// public:
//     string longestPalindrome(string s) {
//         string rev, sub, largest;
//         int max=0, len=s.size();
//         for(int i=0; i<len-max+1; i++){
//             for(int j=max; j<len+1-i; j++){
//                 sub=s.substr(i,j);
//                 cout<<"sub: "<<sub<<endl;
//                 rev=sub;
//                 reverse(rev.begin(), rev.end());
//                 if(sub==rev&&(sub.size())>=max){
//                     max=sub.size();
//                     largest=sub;
//                 }
//             }
//         }
//         return largest;
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of palindrome
        };

        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(i, i);     // Odd-length palindrome
            int len2 = expandAroundCenter(i, i + 1); // Even-length palindrome
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};

