class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 1시간의 각도는 30도
        // 3시 15분이면 
        // 90 + (0.25) * 30
        // 97.5 
        // 90

        //15분이라는건 90도와 270도를 갖고있다
        //3시 15분의 hour바늘은 97.5와 262.5 를 갖고있다
        //30분이라는건 180도와 180도를 갖고있다
        //3시 30분의 hour바늘은 105도와 255도를 갖고있다
        
        double mindeg = ((double)minutes / 60.f) * 360.f;
        double hourdeg = (double)(hour % 12) * 30.f + ((double)minutes / 60.f) * 30.f;
        double answer = min(abs(hourdeg + 360.f - mindeg), abs(hourdeg-mindeg));
        answer = min(answer, abs(mindeg + 360.f - hourdeg));
        
        return answer;
    }
};