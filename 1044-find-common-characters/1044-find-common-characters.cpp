/*
Let's consider an example to understand the process:

Input List: ["bella", "label", "roller"]
Step 1: Count characters in "bella" -> last = [1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] Step 2: Intersection with "label"
-> last = [1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0] Step 3: Intersection with "roller" -> last = [1, 1, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] Step 4: Construct result
vector -> result = ["e", "l", "l"]
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize the frequency count for the first word
        vector<int> commonCount = countChars(words[0]);

        // Update the frequency count to find common characters
        for (int i = 1; i < words.size(); i++) {
            vector<int> currentCount = countChars(words[i]);
            for (int j = 0; j < 26; j++) {
                // Keep the minimum count of each character
                commonCount[j] = min(commonCount[j], currentCount[j]);
            }
        }

        // Collect the common characters based on their counts
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (commonCount[i] > 0) {
                result.push_back(string(1, 'a' + i));
                commonCount[i]--;
            }
        }

        return result;
    }

private:
    // Helper function to count the frequency of each character in a string
    vector<int> countChars(const string& str) {
        vector<int> frequency(26, 0);
        for (char c : str) {
            frequency[c - 'a']++;
        }
        return frequency;
    }
};
