class Encrypter {
public:
    map<char,string> mp;
    map<string,int> decrypted;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++){
            mp[keys[i]] = values[i];
        }
        for(int i = 0; i < dictionary.size(); i++){
            decrypted[encrypt(dictionary[i])]++;
        }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(int i = 0; i < word1.size(); i++){
            if(mp.find(word1[i]) == mp.end()){
                return "";
            }
            ans += mp[word1[i]];
        }
        return ans;
    }
    
    int decrypt(string word2) {
       if(decrypted.find(word2) == decrypted.end()){
           return 0;
       }
       return decrypted[word2];
    }
};

