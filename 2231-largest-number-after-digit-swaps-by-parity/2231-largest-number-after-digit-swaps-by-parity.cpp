class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>odd;
        priority_queue<int>even;
        int temp=num;
        while(temp != 0){
            int rem=temp%10;
            temp=temp/10;
            if(rem % 2 == 0){
                even.push(rem);
            }
            else{
               odd.push(rem);
            }
        }
        int res=0;
        string a=to_string(num);
        for(int i=0;i<a.size();i++){
            if((a[i]-'0') % 2 == 0){
                res=res*10+even.top();
                even.pop();
            }
            else{
                res=res*10+odd.top();
                odd.pop();
            }
        }
        return res;
    }
};