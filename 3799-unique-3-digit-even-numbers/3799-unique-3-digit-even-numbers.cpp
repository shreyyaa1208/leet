class Solution {
public:

void findNumbers(std::vector<int>& digits, std::set<int>& result_set, int current_num, std::vector<bool>& used) {
    // Base Case: Once we have a 3-digit number, check it and stop this path.
    if (current_num >= 100) {
        if (current_num % 2 == 0) {
            result_set.insert(current_num);
        }
        return; // Stop building, this number is long enough
    }

    // Recursive Step: Iterate through all digits to choose the next one.
    for (int i = 0; i < digits.size(); ++i) {
        // Condition 1: Don't use the same digit instance twice in one number.
        if (used[i]) {
            continue;
        }

        // Condition 2: The first digit of a 3-digit number cannot be zero.
        if (current_num == 0 && digits[i] == 0) {
            continue;
        }

        // --- Action ---
        used[i] = true; // Mark this digit as used for this path.

        // --- Recurse ---
        // Build the next level of the number and call the function again.
        findNumbers(digits, result_set, current_num * 10 + digits[i], used);

        // --- Backtrack ---
        // Un-mark the digit so it can be used in different permutations.
        used[i] = false;
    }
}


int totalNumbers(std::vector<int>& digits) {
    // The set to store our unique 3-digit even numbers.
    std::set<int> result_set;

    // A boolean vector to keep track of which digits are used in the current permutation.
    std::vector<bool> used(digits.size(), false);

    // Start the recursion with an initial number of 0.
    findNumbers(digits, result_set, 0, used);

    // The final answer is the number of unique elements found.
    return result_set.size();
}
};