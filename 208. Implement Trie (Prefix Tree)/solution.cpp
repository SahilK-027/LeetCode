/*
296 ms
137.1 MB

TC : O(N * avg L) // where 'N' is the number of strings we want to insert in Trie and 'avgL' is the average length of 'N' strings
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Implementation
*/

class Trienode{
public:
    char data;
    Trienode* children[26];
    bool isTerminal;

    Trienode(char ch){
        this->data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    Trienode* root;
    Trie() {
        root = new Trienode('\0');
    }
    
    // Insertion of word
    void insertUtil(Trienode* root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // Assume word will be in lower case
        int index = word[0] - 'a';
        Trienode* child;

        // If already present move ahead
        if(root->children[index]  != NULL){
            child = root->children[index];
        }else{
            // If Absent create and attach
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        insertUtil(root, word);
    }
    

    // Searching word
    bool searchUtil(Trienode* root, string word){
        // Base case
        if(word.length() == 0){
            if(root->isTerminal){
                return true;
            }else{
                return false;
            }
        }

        int index = word[0] - 'a';
        Trienode* child;

        // WORD PRESENT
        if(root->children[index] != NULL){
             child = root->children[index];
        }else{
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
    


    bool startsWithUtil(Trienode* root, string word){
        // Base case
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        Trienode* child;

        // WORD PRESENT
        if(root->children[index] != NULL){
             child = root->children[index];
        }else{
            return false;
        }

        // Recursion
        return startsWithUtil(child, word.substr(1));
    }
    bool startsWith(string word) {
        return startsWithUtil(root, word);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */