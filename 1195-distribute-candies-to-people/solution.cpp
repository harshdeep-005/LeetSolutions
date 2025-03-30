class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> arr(num_people, 0);
        int i=0;
        while(candies>=0){ 
            arr[i % num_people] += min(i + 1, candies);
	        i += 1;
	        candies -= i;
        }
        return arr;
    }
};
