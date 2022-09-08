class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
          string ans; 
        int k=K;
        for (int i = S.size()-1; i >= 0; --i) {
            if (S[i] != '-') {
                if (k == 0) {
                    ans.push_back('-');
                    k = K; 
                }
                ans.push_back(toupper(S[i])); 
                --k; 
            }
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};