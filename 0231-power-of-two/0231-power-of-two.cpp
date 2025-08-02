class Solution {
public:
    bool isPowerOfTwo(int n) {
    // Base case for failure: Powers of two must be positive.
    if (n <= 0) {
        return false;
    }
    // Base case for success: If we've divided down to 1, it's a power of two.
    if (n == 1) {
        return true;
    }
    // If n is odd at any point (and not 1), it fails.
    if (n % 2 != 0) {
        return false;
    }
    // Recursive Step: If n is even and greater than 1, check n / 2.
    return isPowerOfTwo(n / 2);
}
};