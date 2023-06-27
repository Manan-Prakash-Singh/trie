#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

struct trie_struct;
typedef struct trie_struct trie_t;

struct trie_struct {
	trie_t *arr[26];
	int is_terminal;
	int val;
};

trie_t* create_trie();
trie_t* destroy_trie();
int insert_key(trie_t* t, const char* key, int val);

int main(int argc, char **argv) {

}

trie_t *create_trie() {
	trie_t *t = malloc(sizeof(*t));
	t->is_terminal = 0;
	t->val = 0;

	for (int i = 0; i < 26; i++) {
		t->arr[i] = NULL;
	}

	return t;
}

int insert_key(trie_t* t, const char* key, int val){
    if(!t){
        fprintf(stderr, "null value for trie\n");
        return -1;
    }

    int len = strlen(key);

    trie_t* cur_trie = t;
    for(int i=0; i<len; i++){
        int c = key[i];
        if(!t->arr[c]){
            trie_t* new_trie = init_trie();
            new_trie->
        }
    }
}