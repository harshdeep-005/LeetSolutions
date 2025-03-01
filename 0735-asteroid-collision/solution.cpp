// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& x) {
//         vector<int> ans;
//         stack<int> s;
//         int i=x.size()-1;
//         while(i>=0){
//             if(x[i]>0){
//                 while(s.top()<0&&!s.empty()){
//                     if(abs(x[i])>abs(s.top()))s.pop();
//                 }
//                 s.push(x[i]);
//                 if(!(abs(x[i])>abs(s.top())))s.pop();
//                 if(s.top()>0)s.push(x[i]);
//             }
//             else s.push(x[i]);
//             i--;
//         }
//         for(int j=s.size(); j>=0;j--){
//             ans.push_back(s.top());
//             s.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& x) {
        stack<int> s;
        
        for (int i = 0; i < x.size(); i++) {
            bool destroyed = false;
            
            while (!s.empty() && x[i] < 0 && s.top() > 0) { 
                if (abs(x[i]) > s.top()) {
                    s.pop(); 
                    continue; 
                } else if (abs(x[i]) == s.top()) {
                    s.pop(); 
                }
                destroyed = true;
                break;
            }
            
            if (!destroyed) s.push(x[i]);
        }

        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
