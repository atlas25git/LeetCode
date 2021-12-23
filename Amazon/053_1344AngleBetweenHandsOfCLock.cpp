class Solution {
public:
    double angleClock(int hour, int minutes) {
        //since hour hand completes 360* in 12 hours
        //1hour = 30*
        //minute hand completes 360* in 60 minutes
        //1min = 6*
        
        double sectorH = (hour%12)*30 + (minutes/60.0)*30;
        double sectorM = (minutes)*6;
        double angle = abs(sectorH - sectorM);
        if(angle>180)angle = 360-angle;
        return angle;
    }
};