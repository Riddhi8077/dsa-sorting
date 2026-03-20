#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long a = labs(dividend);
        long b = labs(divisor);

        int result = 0;

        while (a >= b) {
            long temp = b, multiple = 1;

            while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }
        
        return negative ? -result : result;
    }
};
