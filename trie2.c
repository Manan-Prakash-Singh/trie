#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define SIZE 26

typedef struct trie_struct {
	u_int8_t *matrix[26];
	int *val[26];
	int len;
	int cap;
} trie_t;

trie_t create_trie(int l);
void insert_key(trie_t *trie, const char *key);
int search_key(trie_t *trie, const char *key);
void delete_trie(trie_t *trie);
void print_keys(trie_t *trie, char *buff, int j);

int main() {
	trie_t t = create_trie(14);

	insert_key(&t, "manan");
	insert_key(&t, "man");
	insert_key(&t, "program");
	insert_key(&t, "prakash");
	insert_key(&t, "prakish");
	char buff[100];
	print_keys(&t, buff, 0);
	delete_trie(&t);
}

void print_keys(trie_t *trie, char *buff, int j) {

	for (int k = 0; k < 26; k++) {
		if (trie->matrix[k][j]) {
			buff[j] = 'a' + k;
			if (trie->val[k][j]) {
				buff[j + 1] = '\0';
				printf("%s\n", buff);
			}
			print_keys(trie, buff, j + 1);
		}
	}
}
trie_t create_trie(int l) {
	trie_t t;

	for (int i = 0; i < SIZE; i++) {
		t.matrix[i] = calloc(l, sizeof(u_int8_t));
		t.val[i] = calloc(l, sizeof(int));
	}
	t.len = 0;
	t.cap = l;

	return t;
}

void insert_key(trie_t *trie, const char *key) {
	int len = strlen(key);
	int i = 0;

	for (; i < len; i++) {
		int j = key[i] - 'a';
		trie->matrix[j][i] = 1;
		if (i == len - 1) {
			trie->val[j][i]++;
		}
	}
}

int search_key(trie_t *trie, const char *key) {
	int len = strlen(key);
	int i = 0, ret = 0;

	for (; i < len; i++) {
		int j = key[i] - 'a';
		if (!trie->matrix[j][i]) {
			return 0;
		}
		if (i == len - 1) {
			ret = trie->val[j][i];
		}
	}

	return ret;
}

void delete_trie(trie_t *t) {
	for (int i = 0; i < SIZE; i++) {
		if (t->matrix[i]) {
			free(t->matrix[i]);
			t->matrix[i] = NULL;
		}
		if (t->val[i]) {
			free(t->val[i]);
			t->val[i] = NULL;
		}
	}
}