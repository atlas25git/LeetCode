class TrieNode{
    public:
        bool word;
        TrieNode* children[26];
        TrieNode()
        {
            word=false;
            //memset(children,NULL,sizeof(children));
            for(int i=0;i<26;i++)
                children[i] = NULL;
        }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    TrieNode* root = new TrieNode();    
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c: word){
            if(!node->children[c-'a']){
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return search(word.c_str(),root);
    }

 private:
    
    bool search(const char* word,TrieNode* node)
    {
        for(int i=0;word[i] && node;i++){
            if(word[i]!='.'){
                node = node->children[word[i]-'a'];
            }else{
                TrieNode* tmp = node;
                for(int j=0;j<26;j++)
                {
                    node = tmp->children[j];
                    if(search(word+i+1,node))return true;
                }
            }
        }
        return node && node->word;
    } 
};