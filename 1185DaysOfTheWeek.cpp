class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string s = "";
        vector<int> t = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if(month<3)year-=1;
        int i = (year + year/4 - year/100 + year/400 + t[month-1] +day)%7;
        switch (i) {
            case 1: s = "Monday"; break;
            case 2: s = "Tuesday"; break;
            case 3: s = "Wednesday"; break;
            case 4: s = "Thursday"; break;
            case 5: s = "Friday"; break;
            case 6: s = "Saturday"; break;
            case 0: case 7: s = "Sunday"; break;
            default: ; 
        }
        return s;
    }
};