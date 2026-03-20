#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend > 0) ^ (divisor > 0);

        int a = dividend;
        int b = divisor;

        if (a > 0) a = -a;
        if (b > 0) b = -b;

        long long result = 0;  

        while (a <= b) {
            int temp = b;
            int multiple = 1;

            while (temp >= (INT_MIN >> 1) && a <= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        if (!negative) return (int)result;
        return (int)(-result);
    }
};
