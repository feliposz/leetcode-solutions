class OrderedStream {
public:
    vector<string> data;
    vector<bool> arrived;
    int ptr = 0;
    
    OrderedStream(int n) {
        data.resize(n);    
        arrived.resize(n);
    }
    
    vector<string> insert(int idKey, string value) {
        data[idKey-1] = value;
        arrived[idKey-1] = true;
        
        vector<string> result;
        while (arrived[ptr] && (ptr < data.size())) {
            result.push_back(data[ptr++]);
        }
        
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */