#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        // Calculate the position of the most significant bit (MSB) of n
        int bitLength = 0;
        int temp = n;
        while (temp > 0) {
            bitLength++;
            temp >>= 1;
        }
        
        return 1 << bitLength;
    }
};
