class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int d=0;
        bool flag=false;
        int res=-1;
        for(int i=0;i<seats.size();i++){
            if(seats[i] == 0){
                d++;
            }
            else if (seats[i] == 1 && flag == false){
                flag = true;
                res=max(res,d);
                d=0;
            }
            else{
                res=max(res,(d+1)/2);
                d=0;
            }
        }
        cout<<res<<endl;
        if(seats[seats.size()-1] == 0){
        res=max(res,d);
        }
        cout<<res<<endl;
        return res;
    }
};