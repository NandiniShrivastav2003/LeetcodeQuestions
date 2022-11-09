class Solution {
public:
    long long count(string a, string b)
{
    int m = a.length();
    int n = b.length();
 
   vector<vector<long long>> lookup (m+1,vector<long long>(n+1,0));
   
   // If only first string is empty and second
    // string is not empty, return 0
   for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
 
    // If both first and second string is empty,
    // or if second string is empty, return 1
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
 
   for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
             // If last characters are same
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] +
                               lookup[i - 1][j];
                 
            else
			// If last characters are different, ignore
            // last char of first string 
			 lookup[i][j] = lookup[i - 1][j];
        }
    }
  
    return lookup[m][n];
}
    long long maximumSubsequenceCount(string text, string pattern) {
    
        
        return max(count(pattern[0]+text,pattern),count(text+pattern[1],pattern));
        
        
    }
};