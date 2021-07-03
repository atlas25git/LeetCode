class MinStack {
    #define ll long long int
    
public:
    /** initialize your data structure here. */
    stack<ll> s;
    ll minE;
    MinStack() {
        //s.clear();
        minE=INT_MAX;
    }
    
    void push(ll val) {
        
        if(s.empty()){
        minE=val;
        s.push(val);}
        
        else{
            if(val<minE)
            {   
                
                ll val2 = val;
                val2+=val2;
                ll Vt = val2 -minE;
                s.push(Vt);
                minE=val;
                
            }
        
        else s.push(val);
        }
    }
    
    void pop() {
              //cout<<getMin()<<endl;;
               s.pop();
        return;
            
    }
    
    int top() {
        if(s.top()<minE)
        {
        
            return minE;
        }
        else return s.top();
    }
    
    int getMin() {
        if(s.top()>=minE)
        {       
                if(minE==-10)cout<<"if"<<endl;
                return minE;
        }
        else
        {                   
            if(minE==-10)cout<<"else"<<endl;
            ll res=minE;
            minE = 2*minE - s.top();
            return res;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */