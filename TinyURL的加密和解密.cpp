class Solution {
public:
    unordered_map<string, string> umap;
    // Encodes a URL to a shortened URL.
    string stdcodes = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encode(string longUrl) {
        string codes(6, ' ');
        do {
            for(int i = 0; i < 6; i++) {
                codes[i] = rand() % stdcodes.length();
            }
        } while(umap.count(codes));
        umap[codes] = longUrl;
        return codes;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return umap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));