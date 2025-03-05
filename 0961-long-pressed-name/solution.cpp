// class Solution {
// public:
//     bool isLongPressedName(string name, string typed) {
//         int i = 0, j = 0;
//         while (i < name.size() && j < typed.size()) {
//             if (name[i] == typed[j])
//                 i++;
//             j++;
//         }
//         while(j<typed.size())if(name[i-1]!=typed[j++])return false;     
//         if (i == name.size())return true;
//         return false;
//     }
// };
#include <string>

class Solution {
public:
    bool isLongPressedName(std::string name, std::string typed) {
        int i = 0, j = 0;
        
        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i++; 
            } 
            else if (j == 0 || typed[j] != typed[j - 1]) {
                return false;  
            }
            j++;  
        }
        
        return i == name.size();  
    }
};

