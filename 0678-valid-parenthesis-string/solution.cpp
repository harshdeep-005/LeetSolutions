// class Solution {
// public:
//     bool checkValidString(string s) {
//         int i=0;
//         int cnt=0, c=0;
//         if(s[0]==')'||s[s.size()-1]=='(')return false;
//         while(i<s.size()){
//             if(s[i]=='(')c++;
//             if(s[i]==')')c--;
//             if(s[i]=='*')cnt++;
//             i++;
//         }
//         cout<<cnt<<" "<<c;
//         if(cnt>=abs(c)||c==0)return true;
//         return false;
//     }
// };
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++; 
                high++;
            } 
            else if (c == ')') {
                low = max(0, low - 1);
                high--;
            } 
            else { 
                low = max(0, low - 1);
                high++;
            }

            if (high < 0) return false; 
        }

        return low == 0; 
    }
};

