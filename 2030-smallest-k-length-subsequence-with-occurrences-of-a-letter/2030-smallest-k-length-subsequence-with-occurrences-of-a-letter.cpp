class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
         string ans;
        int count = 0;
        for (auto c : s) {
            if (c == letter)
                ++count;
        }
        int used = 0;
        for (int i = 0; i < s.size(); ++i) {
            const auto c = s[i];            
			// Check if it's safe and necessary to pop elements from the stack
			// 1. If we have enough characters remaining in the string
			// 2. If c != letter, does it produce a smaller valid subsequence with the remaining elements?
			// 3. If c == letter, do we need to pop from the stack so the final subsequence length is k?
            while (!ans.empty() && ans.size() - 1 + s.size() - i >= k && 
                   ((ans.back() != letter && c < ans.back()) ||
                    (ans.back() == letter && c < ans.back() && used + count - 1 >= repetition) ||
                    (c == letter && used + k - ans.size() < repetition))) {
                if (ans.back() == letter)
                    --used;
                ans.pop_back();
            }
			// Need to push the new one
            if (ans.size() < k) {                
                if (c == letter) {
                    ++used;                    
                }
                ans.push_back(c);
            }
			// Update how many characters are still available
            if (c == letter)
                --count;
        }
        
        return ans;
    
    }
};