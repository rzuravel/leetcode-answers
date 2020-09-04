/**

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

Submission:

Accepted Solutions Runtime Distribution: beats 46.81 % of cpp submissions.
Accepted Solutions Memory Distribution: beats 97.04 % of cpp submissions.

**/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() < 2) return false;
        
        for (int i = 2; i <= s.size(); ++i) {
            // if it's a factor
            if (s.size() % i == 0) {
                
                bool answer = true;
                for (int j = 0; j < s.size() / i; ++j) {
                    char key = s[j];
                    
                    for (int k = 1; k < i; ++k) {
                        //printf("i = %i, j = %i, k = %i, s.size() = %i\n", i, j, k, s.size());
                        
                        answer = answer && (key == s[(s.size() / i) * k + j]);
                    }
                }
                
                if (answer) return true;
            }
        }
        
        return false;
    }
};
