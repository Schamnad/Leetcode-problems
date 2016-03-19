// 30. Substring with Concatenation of All Words
//
// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]
//
// You should return the indices: [0,9].
// (order does not matter).

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num = words.size();
        int len = words[0].size();
        int total = num*len;
        vector<int> result;

        unordered_map<string,int> wordMap;

        for(auto x: words){
        	wordMap[x]++;
        }

        for(int i = 0 ; i + total-1 < s.size();i++){
        	unordered_map<string,int> temp;
        	int j;
        	for(j = 0; j < num; j++){
        		string meh = s.substr(i+j*len,len);

        		if(!wordMap[meh])
        			break;
        		else{
        			temp[meh]++;

        			if(temp[meh] > wordMap[meh])
        				break;
        		}
        	}
        	if(j == num)
        		result.push_back(i);
        }
        return result;
    }
};
