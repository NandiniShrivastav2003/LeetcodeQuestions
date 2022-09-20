class Solution {
public:

    bool isPalindromic(string a,int i,int j)
 {   
        	int l=i;
	int r=j;
	while(l<r){
		if(a[l] !=  a[r]){
          return 0;
		}
		l++;r--;
	}
	return 1;
}
    int countSubstrings(string s) {
        int count=0;
	for(int i=0;i<s.size();i++){
	    for(int j=i;j<s.size();j++){
if(isPalindromic(s,i,j)){
	count++;
}
		}
	}
        return count;
    }
};

