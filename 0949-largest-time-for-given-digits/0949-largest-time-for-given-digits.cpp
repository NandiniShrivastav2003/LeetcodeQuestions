class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans="";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(i == j || j == k || k == i){
                        continue;
                    }
                    int l=6-i-j-k;
                    string hh=to_string(arr[i])+""+to_string(arr[j]);
                    string mm=to_string(arr[k])+""+to_string(arr[l]);
                    if(hh < "24" && mm <"60" && ans< hh+mm){
                        ans=hh+mm;
                    }
                }
            }
        }
        string temp="";
        if(ans == ""){
            return ans;
        }
     //   cout<<ans[3]<<endl;
        temp=to_string(ans[0]-'0')+to_string(ans[1]-'0')+":"+to_string(ans[2]-'0')+to_string(ans[3]-'0');
        return temp;
    }
};
