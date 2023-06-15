class Solution {
    public static String solve(String s,int mid){
        long mod=1000_000_007;
        long pow=1;
        long hv=0;
        int pr=31;
        for(int ei=mid-1;ei>=0;ei--){
            hv=(hv+((s.charAt(ei)-'a'+1)*pow) % mod)%mod;
        
      if(ei > 0){
          pow=(pow*pr)%mod;
      }
        }
        HashMap<Long,List<Integer>>map=new HashMap<>();
        map.put(hv,new ArrayList<>());
        map.get(hv).add(0);
        for(int ei=mid,si=0;ei<s.length();ei++,si++){
            hv=(hv-(((s.charAt(si)-'a'+1)*pow)%mod)+mod)%mod;
            hv=(hv*pr)%mod;
            hv=(hv+(s.charAt(ei)-'a'+1))%mod;
            if(map.containsKey(hv)){
                String curr=s.substring(si+1,ei+1);
                for(int st:map.get(hv)){
                    if(curr.equals(s.substring(st,st+mid))){
                        return curr;
                    }
                }
                map.get(hv).add(si+1);
            }
            else{
                map.put(hv,new ArrayList<>());
                map.get(hv).add(si+1);
            }
        }
        return "";
        
        
    }
    public String longestDupSubstring(String s) {
        int lo=0;
        int hi=s.length();
        String res="";
        while(lo <= hi){
            int mid=(lo+hi)/2;
            String temp=solve(s,mid);
            if(temp.length() > 0){
                lo=mid+1;
                res=temp;
            }
            else{
                hi=mid-1;
            }
        }
        
        return res;
    }
}