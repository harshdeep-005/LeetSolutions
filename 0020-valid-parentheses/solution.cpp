class Solution {
public:
    bool isValid(string s) {
        stack<char>a;
        int i=0;
        char c;
        while(s[i]){
            c=s[i];
            i++;
            if(c=='('||c=='['||c=='{'){
                a.push(c);
            }
            else {
                if (a.empty()) return false;

                if ((c == ')' && a.top() == '(') ||
                    (c == ']' && a.top() == '[') ||
                    (c == '}' && a.top() == '{')) {
                    a.pop(); 
                } else {
                    return false; 
                }
            }
        }
        return a.empty();

    }
};
