class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int count = 1;
        while (s.size() < b.size()) {
            s += a;
            count++;
        }
        if (s.contains(b))
            return count;
        s += a;
        if (s.contains(b))
            return count + 1;
        return -1;
    }
};