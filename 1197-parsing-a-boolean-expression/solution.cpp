class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> s;

        for (char a : exp) {
            if (a == ',' || a == '(')
                continue;  
            if (a == 't' || a == 'f' || a == '!' ||
                a == '&' || a == '|') {
                s.push(a);
            }
            else if (a == ')') {
                bool hasTrue = false, hasFalse = false;

                while (s.top() != '!' && s.top() != '&' && s.top() != '|') {
                    char topValue = s.top();
                    s.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }
                char op = s.top();
                s.pop();
                if (op == '!') {
                    if(hasTrue) s.push('f');
                    else s.push('t');
                } 
                else if (op == '&') {
                    if(hasFalse) s.push('f');
                    else s.push('t');
                } 
                else {
                    if(hasTrue) s.push('t');
                    else s.push('f');
                }
            }
        }
        if(s.top() == 't') return true;
        else return false;
    }
};
