// 68. Text Justification
//
// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is inserted between words.
//
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

class Solution {
public:
	void justifyLine(vector<string>& words,int startPoint, int endPoint, std::vector<string> &result,int maxWidth){
		string temp;
		temp = words[startPoint];

		if(startPoint == endPoint){
			temp.append(maxWidth-temp.length(),' ');
			result.push_back(temp);
			return;
		}else if(endPoint == words.size()-1){
			temp += ' ';
			for(int j =startPoint+1; j<= endPoint; j++){
				temp +=words[j] + ' ';
			}
			temp.append(maxWidth-temp.length(),' ');
			result.push_back(temp);
			return;
		}

		int wordsLength = 0;
		int wordsCount = endPoint-startPoint;
		int spaces = maxWidth - temp.size();

		for(int j =startPoint+1; j<= endPoint; j++){
			wordsLength += words[j].size();
		}
		spaces -= wordsLength;

		int spaceWord = spaces/(wordsCount);
		int mod = spaces % wordsCount;

		for(int j = startPoint+1; j <= endPoint; j++){
			if(mod > 0){
				temp.append(spaceWord+1,' ');
				mod--;
			}else{
				temp.append(spaceWord,' ');
			}
			temp += words[j];
		}

		result.push_back(temp);
	}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordsCount = 0;
        int startPoint = 0;
        int previous = 0;
        vector<string> result;
        if(words.size() == 1){
            string temp = words[0];
            temp.append(maxWidth-temp.length(),' ');
			result.push_back(temp);
			return result;
        }

        for(int i = 0 ; i < words.size(); i++){
        	wordsCount += words[i].length();
        	if(startPoint == words.size()-1){
        	    cout <<"Here";
        	    justifyLine(words,startPoint,startPoint,result,maxWidth);
        	}else if(wordsCount == maxWidth){
        		cout <<wordsCount <<" " << startPoint <<" " << i <<"\n";
          		justifyLine(words,startPoint,i,result,maxWidth);
        		startPoint = i+1;
	     		wordsCount = 0;
        	}else if(wordsCount > maxWidth){
          		justifyLine(words,startPoint,i-1,result,maxWidth);
        		startPoint = i;
        		if(startPoint == words.size()-1){
        	    cout <<"I'm here\n" ;
        	    	justifyLine(words,startPoint,i,result,maxWidth);
        		}
        		wordsCount = words[i].length()+1;
        	}else if(i == words.size()-1){
        	    justifyLine(words,startPoint,i,result,maxWidth);
        	}else{
        		wordsCount++;
        	}
        }
        return result;

    }
};
