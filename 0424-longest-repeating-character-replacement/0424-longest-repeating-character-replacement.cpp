class Solution {
public:
    int check( map<char,int>mp){
        int ans=0;
        for(auto i:mp){
            if(i.second > ans){
                ans=i.second;
            }
        }
        return ans;
        
    }
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int maxcount=0;
        int ans=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            maxcount=max(maxcount,++mp[s[right]-'A']);
            if(right-left+1-maxcount > k){
                mp[s[left]-'A']--;
                left++;
                maxcount=check(mp);
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};