class Solution {
public:

    unordered_map<int, string> db;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int id = rand();
        
        while (db.find(id) != db.end()) {
            id = rand();
        }
        
        db[id] = longUrl;
        
        return to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = stoi(shortUrl);
        return db[id];
    }
    
    
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));