#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

struct trie_struct;
typedef struct trie_struct trie_t;

struct trie_struct {
	trie_t *arr[26];
	int val;
};

trie_t *create_trie();
trie_t *destroy_trie();
void insert_key(trie_t *t, const char *key, int val);
int search(trie_t *t, const char *key);

int main(int argc, char **argv) {}

trie_t *create_trie() {

	trie_t *t = malloc(sizeof(*t));
	t->val = 0;

	for (int i = 0; i < 26; i++) {
		t->arr[i] = NULL;
	}

	return t;
}

void insert_key(trie_t *t, const char *key, int val) {
	assert(t != NULL && "null value for the trie");
	int len = strlen(key);

	trie_t *cur_trie = t;

	for (int i = 0; i < len; i++) {
		int c = key[i] - 'a';
		if (!cur_trie->arr[c]) {
			cur_trie->arr[c] = create_trie();
		}

		cur_trie = cur_trie->arr[c];
	}

	cur_trie->val++;
}

int search(trie_t *t, const char *key) {
	assert(t != NULL && "Null trie given.");

	int len = strlen(key);

	trie_t *itr = t;
	trie_t *prev = t;

	for (int i = 0; i < len; i++) {
		int c = key[i] - 'a';
		if (!itr->arr[c]) {
			return 0;
		}
		prev = itr;
		itr = itr->arr[c];
	}

	return prev->val;
}