// class Solution {
// public:
//     string removeDuplicates(string s) {
//         int len=s.size(), i=0;
//         while(i<len-1){
//             if(s[i]==s[i+1]){
//                 if(len==i+2){
//                     s=s.substr(0,i);
//                 }
//                 else{
//                     s=s.substr(0,i)+s.substr(i+2,len-(i+2));
//                     i=0;
//                 }
//             }
//             else i++;
//             len=s.size();
//         }
//         return s;
//     }
// };
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ss="";
        while(!st.empty()){
            ss+=st.top();
            st.pop();
        }reverse(ss.begin(), ss.end());
        return ss;
    }
};
