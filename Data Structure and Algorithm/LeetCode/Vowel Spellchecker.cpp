class Solution {
public:
    
    string getUpper(string s)
    {
        int size = s.length();
        string upper;
        for(int i = 0; i < size; i++){
            if( s[i] >= 'a' and s[i] <= 'z'){
                int temp = s[i] - 'a';
                upper += 'A' + temp;
            }
            else{
                upper += s[i];    
            }

        }
        
        return upper;
    }
    
    string getStartedVowelStr(string s)
    {
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int size = s.length();
        string ve;
        for(int i = 0; i < size; i++){
            bool added = false;
            for(int j = 0; j < 10; j++){
                if(s[i] == vowels[j]){
                    ve += '*';
                    added = true;
                    break;
                }
            }
            
            if(added == false){
                if( s[i] >= 'a' and s[i] <= 'z'){
                    int temp = s[i] - 'a';
                    ve += 'A' + temp;
                }
                else{
                    ve += s[i];    
                }
            }                
        }
        
        return ve;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> exactMatch;
        unordered_map<string, string> upperOnly;
        unordered_map<string, string> vowelError;
        
        for(auto s : wordlist){
            exactMatch[s] = s;
             cout << s << "\n";
            /////////////////////
            string upper = getUpper(s);
            if(upperOnly.find(upper) == upperOnly.end()){
                upperOnly[upper] = s;    
            }
            else{
                cout << "upper exist!" << "\n";
            }
            cout << upper << " " << upperOnly[upper] << "\n";            
            /////////////////////
            string ve = getStartedVowelStr(s);
            if(vowelError.find(ve) == vowelError.end()){
                vowelError[ve] = s;    
            }
            else{
                cout << "vowelError exist!" << "\n";
            }
            cout << ve << " " << vowelError[ve] << "\n";
        }
        
        vector<string> result;
        for(auto s : queries){
            string u = getUpper(s);
            string v = getStartedVowelStr(s);
            if(exactMatch.find(s) != exactMatch.end()){
                result.push_back(exactMatch[s]); 
            }
            else if(upperOnly.find(u) != upperOnly.end()){
                result.push_back(upperOnly[u]);
            }
            else if(vowelError.find(v) != vowelError.end()){
                result.push_back(vowelError[v]);
            }
            else{
                result.push_back("");
            }
        }
        
        return result;
    }
};
