class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;
            int j =1;
            for(int i =1;i<n;i++)
            {
                if(nums[i]!=nums[j-1])
                {
                    nums[j++] = nums[i];
                }
            }
            return j;
        }
    };