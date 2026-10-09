class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsetsunique;
        vector<int> subset;
        
        backtrack(0, nums, subset, subsetsunique);
        return subsetsunique;
    }

    void backtrack(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& subsetsunique) {
        // 1. Save the current subset we built into our 2D result vector
        subsetsunique.push_back(subset);

        // 2. Loop through remaining numbers starting from 'index'
        for (int j = index; j < nums.size(); j++) {
            // 3. Skip duplicates at the same recursion level
            if (j > index && nums[j] == nums[j - 1]) {
                continue;
            }

            // 4. Include nums[j], explore further, then remove it (backtrack)
            subset.push_back(nums[j]);
            backtrack(j + 1, nums, subset, subsetsunique);
            subset.pop_back();
        }
    }
};