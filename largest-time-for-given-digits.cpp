/**

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9

**/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> usedIndices = vector<int>();
        int time = traverse(A, usedIndices, 0, 0);
        int hours = time / 60;
        int minutes = time % 60;
        if (hours > 24 || hours < 0 ||
           minutes > 60 || minutes < 0) {
            return "";
        }
        else {
            string hourString = (hours < 10) ? "0" + to_string(hours) : "" + to_string(hours);
            string minuteString = (minutes < 10) ? "0" + to_string(minutes) : "" + to_string(minutes);
            return hourString + ':' + minuteString;
        }
    }
    
    int traverse(vector<int>& A, vector<int>& usedIndices, int hour, int minute) {
        int maxValue = INT_MIN;
        for(int i = 0; i < A.size(); ++i) {
            if (find(usedIndices.begin(), usedIndices.end(), i) == usedIndices.end()) {
                if (usedIndices.size() == 0) {
                    if (A[i] < 3) {
                        usedIndices.push_back(i);
                        maxValue = max(traverse(A, usedIndices, hour+A[i]*10, minute), maxValue);
                        usedIndices.pop_back();
                    }
                }
                else if (usedIndices.size() == 1) {
                    if (hour + A[i] < 24) {
                        usedIndices.push_back(i);
                        maxValue = max(traverse(A, usedIndices, hour + A[i], minute), maxValue);
                        usedIndices.pop_back();
                    }
                }
                else if (usedIndices.size() == 2) {
                    if (A[i] < 6) {
                        usedIndices.push_back(i);
                        maxValue = max(traverse(A, usedIndices, hour, minute + A[i] * 10), maxValue);
                        usedIndices.pop_back();
                    }
                }
                else {
                    return hour * 60 + minute + A[i];   
                }
            }
        }
        
        return maxValue;
    }
};
