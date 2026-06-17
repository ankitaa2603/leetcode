class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                len++;
            }
            else if(ch == '*'){
                if(len > 0) len--;
            }
            else if(ch == '#'){
                len *= 2;
            }
        }
        if(k >= len) return '.';
        for(int i = s.size()-1; i >= 0; i--){
            char ch = s[i];
            if(ch >= 'a' && ch <= 'z'){
                len--;
                if(k == len){
                    return ch;
                }
            }
            else if(ch == '*'){
                len++;
            }
            else if(ch == '#'){
                len /= 2;
                k %= len;
            }
            else if(ch == '%'){
                k = len - 1 - k;
            }
        }
        return '.';
    }
};