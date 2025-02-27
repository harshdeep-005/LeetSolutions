// class Solution {
// public:
//     int val(const string &expr) {
//         stack<int> st;
//         int num = 0, result = 0;
//         char op = '+'; 

//         for (int i = 0; i < expr.size(); i++) {
//             char c = expr[i];

//             if (isdigit(c)) {
//                 num = num * 10 + (c - '0'); 
//             }

//             if (!isdigit(c) || i == expr.size() - 1) { 
//                 if (op == '+') {
//                     st.push(num);
//                 } else if (op == '-') {
//                     st.push(-num);
//                 } else if (op == '*') {
//                     int top = st.top();
//                     st.pop();
//                     st.push(top * num);
//                 }
//                 op = c; 
//                 num = 0; 
//             }
//         }

//         while (!st.empty()) {
//             result += st.top();
//             st.pop();
//         }

//         return result;
//     }
//     void foo(string &st, string num, int target, int n, vector<string> &ans){
//         if(n==num.size()-1){
//             int x=val(num);
//             if(x==target) ans.push_back(st);
//             return;
//         }

//         st+=num[n];
//         foo(st,num,target,n+1,ans);

//         st+='+';
//         foo(st,num,target,n+1,ans);
//         st.pop_back();

//         st+='-';
//         foo(st,num,target,n+1,ans);
//         st.pop_back();

//         st+='*';
//         foo(st,num,target,n+1,ans);
//         st.pop_back();
//     }
//     vector<string> addOperators(string num, int target) {
//         vector<string> ans;
//         string st;
//         foo(st,num,target,0,ans);
//         return ans;
//     }
// };

class Solution {
public:
    void foo(string num, int target, int n, long currVal, long prevNum, string expr, vector<string> &ans) {
        if (n == num.size()) {  
            if (currVal == target) ans.push_back(expr);
            return;
        }

        for (int i = n; i < num.size(); i++) {
            string part = num.substr(n, i - n + 1);
            long currNum = stol(part);

            if (part.size() > 1 && part[0] == '0') break;

            if (n == 0) {
                foo(num, target, i + 1, currNum, currNum, part, ans);
            } else {
                foo(num, target, i + 1, currVal + currNum, currNum, expr + "+" + part, ans);
                foo(num, target, i + 1, currVal - currNum, -currNum, expr + "-" + part, ans);
                foo(num, target, i + 1, currVal - prevNum + (prevNum * currNum), prevNum * currNum, expr + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        foo(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};

