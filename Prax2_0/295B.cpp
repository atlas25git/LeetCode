class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> g;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.empty())
        {
            s.push(num);
            return;
        }
        else if(num<=s.top())
        {
            if(s.size() == g.size())
            {
                s.push(num);
            }
            else{
                g.push(s.top()),
                s.pop(),
                s.push(num);
            }
        }
        else
        {
            if(s.size() == g.size())
            {   
                //sc as the new entrant my be the smalles among the greater element,
                //hence ensuring the corner case.
                g.push(num),
                s.push(g.top()),
                g.pop();
            }
            else{
                g.push(num);
            }
        }
    }
    
    double findMedian() {
        if(g.size() == s.size())return (g.top() + s.top())/2.0;
        return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */