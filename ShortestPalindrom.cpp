// 214. Shortest Palindrome
//
// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
// For example:
//
// Given "aacecaaa", return "aaacecaaa".
//
// Given "abcd", return "dcbabcd".

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() < 2)
        	return s;

        int longest = 1;
        int start, end;
        int len = s.length();
        for(int begin = 0; begin <= len/2 ;){
        	start = begin;
        	end = begin;

        	while(end < len-1 && s[end]==s[end+1])
        		end++;

        	begin = end+1;
        	while(end < len-1 && start > 0 && s[end+1] == s[start-1]){
        		end++;
        		start--;
        	}


        	if(start == 0 && longest < end-start +1)
        		longest = end-start+1;
        }

        string temp = s.substr(longest,len-longest);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
};
