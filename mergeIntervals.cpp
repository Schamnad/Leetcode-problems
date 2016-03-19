// 56. Merge Intervals
//
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	class comp{
	public:
		bool operator()(Interval &l1, Interval &l2){
			if(l1.start < l2.start)
				return true;

			return false;
		}
	};

    vector<Interval> merge(vector<Interval>& intervals) {
        std::vector<Interval> result;

        if(intervals.size() ==0){
            return result;
        }
        sort(intervals.begin(),intervals.end(),comp());
        result.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++){

            //cout << intervals[i-1].end << " " << intervals[i].start << " " << intervals[i].end << "\n";
        	if( intervals[i].start <= result.back().end){
        		Interval temp(result.back().start,max(result.back().end,intervals[i].end));
        		//cout << temp.start << " " << temp.end << " ";
        		result.pop_back();
        		result.push_back(temp);

        	}else{
        		result.push_back(intervals[i]);
        	}
        }

        return result;
    }
};
