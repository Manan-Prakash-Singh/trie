#include <iostream>
#include <string>
using namespace std;

#define SIZE 26

class Trie{
    public:
        void insert_key(string& key);
        bool search_key(string& key);
        void delete_key(string& key);
    private:
        Trie* children[SIZE];
        bool is_terminal;
};

void Trie::insert_key(string& key){
    int n = key.length();
    Trie* t = this;
    for(int i=0; i<n; i++){
        int idx = key[i] - 'a';
        if(!t->children[idx]){
            t->children[idx] = new Trie();
        }
        t = t->children[idx];
    }

    t->is_terminal = true;
}
