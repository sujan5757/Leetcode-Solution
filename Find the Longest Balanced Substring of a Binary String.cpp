class Solution {
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int arr=0;
        int f=s.length();
        for(int i=0;i<f;i++)
        {
            int j=i;
            int count1=0,count2=0;
            for(;j<f;j++){
                if(s[j]=='0')
                    count1++;
                if(s[j]=='1')
                    break;
        }
        int g=j;
        for(;g<f;g++)
        {
            if(s[g]=='1')
                    count2++;
            if(s[g]=='0')
                    break;
            if(count1==count2){
              arr=max(arr,(g-i+1));
            }
        }
       
       }
      return arr;
    }

};
