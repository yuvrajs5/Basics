class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = 0;
        
        for (int num : nums) {
            totalsum += num;
        }
    
        int target = totalsum - x; 
        if (target < 0) return -1; 
    
        int start = 0, currentSum = 0, maxlength = -1;
    
        for (int end = 0; end < n; ++end) {
            currentSum += nums[end]; 
            
            while (currentSum > target && start <= end) {
                currentSum -= nums[start]; 
                start++;
            }
            
            if (currentSum == target) {
                maxlength = max(maxlength, end - start + 1);
            }
        }
        return (maxlength == -1) ? -1 : n - maxlength;
        }
    };