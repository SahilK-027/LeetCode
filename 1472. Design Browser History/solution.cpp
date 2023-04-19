/*
Runtime : 228 ms
Memory : 122.4 MB

TC: O(N)
SC: o(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Stack
*/

class BrowserHistory {
public:
    stack<string> history;
    stack<string> upcoming;
	
    BrowserHistory(string homepage) {
        history.push(homepage);
        stack<string> next;
        upcoming = next;
    }
    
    void visit(string url) {
        history.push(url);
        stack<string> next;
        upcoming = next;
    }
    
    string back(int steps) {
        while(steps > 0 && history.size() > 1) { 
            upcoming.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && upcoming.size() > 0) {
            history.push(upcoming.top());
            upcoming.pop();
            steps--;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */