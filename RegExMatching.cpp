// 10. Regular Expression Matching
//
// Implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

class Solution {
public:
    bool isMatch(string s, string p) {
        int inS = s.size();
        int inP = p.size();

        vector<vector<bool> > f(inS+1,vector<bool>(inP+1,false));

        f[0][0] = true;

        for(int i =1; i<inS+1;i++){
        	f[i][0] = false;
        }

        for(int j = 2; j<inP+1; j++){
        	f[0][j] = (p[j-1] == '*' && f[0][j-2]);
        }

        for(int i =1 ; i < inS+1; i++){
        	for(int j =1 ; j< inP +1; j++){
        		if(p[j-1] !='*'){
        			f[i][j] = f[i-1][j-1] && (s[i-1]==p[j-1] || '.' == p[j-1]);
        		}
        		else{
        			f[i][j] = f[i][j-2] || (s[i-1] == p[j-2] || '.' == p[j-2]) && f[i-1][j];
        		}

        	}
        }

        return f[inS][inP];
    }
};
