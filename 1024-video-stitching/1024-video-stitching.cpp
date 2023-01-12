class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
       
    
        int t=0;
        int mini=0;
        int maxi=0;
        while(maxi < time){
        for(int i=0;i<clips.size();i++){
            int left=clips[i][0];
            int right=clips[i][1];
            if(left <= mini  && right > maxi){
                maxi=right;
            }
        }
            if(mini == maxi){
                return -1;
            }
            mini=maxi;
            t++;
        }
        
        return t;
    }
};