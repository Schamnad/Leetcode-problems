// Leetcode 65. Valid Number
// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true


class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return true;

        int number = 0;
        int period = 0;
        int i =0;

        while(s[i] == ' ')
            i++;

        while(s[s.length() -1] == ' ')
            s.erase(s.length()-1,1);

        if(s[i] == '+' || s[i] == '-')
        i++;

        for(i; i < s.length(); i++){
            if(isdigit(s[i]))
                number++;
            else if(s[i]=='.')
                period++;
            else if(s[i] == 'e'){
                i++;
                break;
            }else{
                return false;
            }
        }

        if(period > 1 || number == 0)
        return false;

        if(s[i-1]=='e'){
            if(s[i] == '+' || s[i] == '-')
                i++;

            number=0;
            period = 0;

            for(i; i < s.length(); i++){
                if(isdigit(s[i]))
                    number++;
                else if(s[i]=='.'){
                    period++;
                }else{
                    return false;
                }
            }

            if(period > 0 || number == 0)
                return false;
        }
        return true;
    }
};
