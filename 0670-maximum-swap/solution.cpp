class Solution {
public:
    int maximumSwap(int num) {
        vector<int> a;
    
    while (num > 0) {
        a.push_back(num % 10);
        num /= 10;
    }
    
    reverse(a.begin(), a.end());
    
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        int maxIdx = i; 
        for (int j = i + 1; j < n; j++) {
            if (a[j] >= a[maxIdx]) {
                maxIdx = j;
            }
        }
        
        
        if (a[maxIdx] > a[i]) {
            swap(a[i], a[maxIdx]);
            break; 
        }
    }
    
    num = 0;
    for (int digit : a) {
        num = num * 10 + digit;
    }
    
    return num;
    }
};
