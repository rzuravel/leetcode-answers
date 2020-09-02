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
