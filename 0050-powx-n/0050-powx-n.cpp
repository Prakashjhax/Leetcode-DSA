class Solution {
public:
    double myPow(double x, int n) {

        long long power = n;     // convert to long long to handle INT_MIN

        if (power < 0) {         // handle negative exponent
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;

        while (power > 0) {
            if (power & 1) {     // if odd
                result *= x;
            }
            x *= x;              // square x
            power >>= 1;         // divide by 2
        }

        return result;
    }
};
