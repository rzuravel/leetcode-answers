/**

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

Submission:

Accepted Solutions Runtime Distribution: beats 94.37 % of cpp submissions.
Accepted Solutions Memory Distribution: beats 90.40 % of cpp submissions.

**/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) return false;
        
        vector<pair<int,int>> numsAndIndices = vector<pair<int,int>>();
        
        for (int i = 0; i < nums.size(); ++i) {
            numsAndIndices.emplace_back(nums[i], i);
        }
        
        sort(numsAndIndices.begin(), numsAndIndices.end());
        
        // slide window
        int left = 0, right = 1;
        while (left < numsAndIndices.size() - 1 && right < numsAndIndices.size()) {
            long int difference = (long int)numsAndIndices[right].first -
                                  (long int)numsAndIndices[left].first;
            
            int indexDifference = numsAndIndices[right].second -
                                  numsAndIndices[left].second;
            if (abs(difference) <= t && abs(indexDifference) <= k) {
                return true;
            }
            else if (abs(difference) > t) {
                ++left;
                if (left == right) ++right;
            }
            else {
                ++right;
            }
        }
        
        return false;
    }
};
