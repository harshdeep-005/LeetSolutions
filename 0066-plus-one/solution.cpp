class Solution {
public:
    vector<int> plusOne(vector<int>& num1) {
        int n = num1.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; --i) {
            int sum = num1[i] + carry;
            num1[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0) return num1; 
        }

        if (carry) num1.insert(num1.begin(), carry);
        return num1;
    }
};

