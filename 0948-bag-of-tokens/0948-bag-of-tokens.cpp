class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        int score=0;
        int left=0;
        int right=arr.size()-1;
        sort(arr.begin(),arr.end());
        while(left<=right){
            if( power >= arr[left]){
                score+=1;
                power-=arr[left];
                left++;
            }
            else if(score>= 1 && left != right){
                
                score-=1;
                power+=arr[right];
                right--;
            }
            else{
                left++;
            }
        }
        return score;
    }
};