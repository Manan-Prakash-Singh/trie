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

