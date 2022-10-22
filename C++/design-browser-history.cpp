class BrowserHistory {
public:
    vector<string> backHistory;
    vector<string> fwdHistory;
    
    BrowserHistory(string homepage) {
        visit(homepage);        
    }
    
    void visit(string url) {
        fwdHistory.clear();
        backHistory.push_back(url);
    }
    
    string back(int steps) {
        while ((steps-- > 0) && (backHistory.size() > 1)) {
            fwdHistory.push_back(backHistory.back());
            backHistory.pop_back();            
        }
        return backHistory.back();;
    }
    
    string forward(int steps) {
        while ((steps-- > 0) && (fwdHistory.size() > 0)) {
            backHistory.push_back(fwdHistory.back());
            fwdHistory.pop_back();            
        }
        return backHistory.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */