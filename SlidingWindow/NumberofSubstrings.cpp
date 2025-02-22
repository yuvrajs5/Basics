class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
            int count =0;
            int a = -1;
            int b =-1;
            int c = -1;
            for(int i =0;i<n;i++)
            {
                if('a' == s[i])
                a = i;
                if('b' == s[i])
                b = i;
                if('c'==s[i])
                c = i;
    
                if(a != -1 && b != -1 && c != -1)
                {
                 count += min(a,min(b, c)) + 1;
                }
            }
            return count;
        }
    };