class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> a;
        
        for (const string& token : tokens) {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
                a.push(stoi(token));
            } else {
                int b = a.top(); a.pop();
                int c = a.top(); a.pop();
                if (token == "+") a.push(c + b);
                else if (token == "-") a.push(c - b);
                else if (token == "*") a.push(c * b);
                else if (token == "/") a.push(c / b);
            }
        }
        
        return a.top();
    }
};

