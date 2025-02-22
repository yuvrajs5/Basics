class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors) {
            int count = 0;
            int n = colors.size();
            for(int i =0;i<n;i++)
            {
                colors.push_back(colors[i]);
            }
            for(int i =0;i<n;i++)
            {
                if(colors[i]==colors[i+2] && colors[i]!= colors[i+1])
                {
                    count+=1;
                }
            }
            return count;
        }
    };