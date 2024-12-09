class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1; // Base case
        }
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {
                 return x * myPow(x, INT_MAX); 
            }
            n = -n; // Safely negate n
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
