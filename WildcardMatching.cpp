// 44. Wildcard Matching
//
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
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
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(string s, string p) {
    	int s1 = 0; int s2 = 0; int numMatch; int startPat=-1;

    	while(s1 < s.length()){
            //cout << "here";
    		if(s2 < p.length() && (s[s1] == p[s2] || p[s2] == '?')){
    			s1++;
    			s2++;
    			cout << s2 << " ";
    			continue;
    		}

    		else if(s2 < p.length() && p[s2] == '*'){
    			numMatch = s1;
    			startPat = s2++;
    			//cout << startPat << " ";
    			continue;
    		}

    		else if(startPat != -1){
    			++numMatch;
    			s1 = numMatch;
    			s2 = startPat + 1;
    			//cout << startPat << " here ";
    			cout << s2 << " ";
    			continue;
    		}

    	    else return false;
    	}

    	while(s2 < p.length() && p[s2] == '*'){
    		s2++;
    	}

    	return s2 == p.length();
    }
};
