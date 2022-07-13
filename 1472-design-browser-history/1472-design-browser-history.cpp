class BrowserHistory {
    string name;
    stack<string> sb;
    stack<string> sf;

public:
    BrowserHistory(string homepage) {
        
        name = homepage;
        sb.push(name);
        
    }
    
    void visit(string url) {
        sb.push(url);
        while(!sf.empty()) sf.pop();

    }
    
    string back(int steps) {
        if(steps >= sb.size()){
            while(sb.size() != 1){
                sf.push(sb.top());
                sb.pop();
            }
        }else{
            while(steps && !sb.empty()){
                sf.push(sb.top());
                sb.pop();
                steps--;
            }
        }
        return sb.top();
        
    }
    
    string forward(int steps) {
        
        if(steps >= sf.size()){
            while(!sf.empty()){
                sb.push(sf.top());
                sf.pop();
            }
        }else{
            while(steps && !sf.empty()){
                sb.push(sf.top());
                sf.pop();
                steps--;
            }
        }
        return sb.top();
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */