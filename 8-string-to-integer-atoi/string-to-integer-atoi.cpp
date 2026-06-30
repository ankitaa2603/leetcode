class Solution {
public:
    int myAtoi(string s) {
      if(s.length()==0)  return 0;
      int i=0;
      while(i<s.size() && s[i]==' ') {
        i++;
      }
      s=s.substr(i); 
      int sign=+1;
      long ans=0;
      int MAX= INT_MAX, MIN= INT_MIN;
      i=0;
      if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {  
            i++;
        }
      while(i < s.length()) {
            if(!isdigit(s[i])) break;  
            int digit = s[i] - '0';
            if(ans > (long)(MAX - digit) / 10) {  
                return sign == 1 ? MAX : MIN;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return (int)(sign * ans);
    }
};