// class Solution {
// public:
//     bool isPossibleDivide(vector<int>& nums, int k) {
//         if(nums.size()%k!=0)return false;
//         set<int>a;
//         for(auto s:nums)a.insert(s);
//         unordered_map<int,int> freq;
//         for(auto s:nums)freq[s]++;
//         while(a.size()>=k){
//             if(a[0]==a[1]-1==a[2]-2){
//                 if(!freq[a[0]]==0)freq[a[0]]--;
//                 if(!freq[a[1]]==0)freq[a[1]]--;
//                 if(!freq[a[2]]==0)freq[a[2]]--;
//                 if(freq[a[0]]==0)a.erase(a[0]);
//                 if(freq[a[0]]==0)a.erase(a[0]);
//                 if(freq[a[0]]==0)a.erase(a[0]);
//             }
//             else return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false; 

        map<int, int> freq;
        for (int num : nums) freq[num]++;

        for (auto it = freq.begin(); it != freq.end(); ) {
            int start = it->first; 
            int count = it->second; 
            
            if (count > 0) {
                for (int i = 0; i < k; i++) {
                    if (freq[start + i] < count) return false; 
                    freq[start + i] -= count;
                }
            }

            while (it != freq.end() && it->second == 0) it++; 
        }

        return true;
    }
};

