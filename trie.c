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

trie_t *create_node();
int destroy_trie(trie_t *t);
void insert_key(trie_t *t, const char *key);
int search_key(trie_t *t, const char *key);
void print_keys(trie_t* t, char* buff, int i);

int main(int argc, char **argv) {
	trie_t* node = create_node();
	insert_key(node,"manan");
	insert_key(node,"man");
	insert_key(node,"mano");
	insert_key(node,"prakash");
	insert_key(node,"prakish");
	insert_key(node,"lmao");
	insert_key(node,"ablu");
	insert_key(node,"bablu");

	char buff[100];
	memset(buff,0,sizeof(buff));
	print_keys(node, buff, 0);
	destroy_trie(node);
}

trie_t *create_node() {

	trie_t *t = malloc(sizeof(*t));
	t->val = 0;

	for (int i = 0; i < 26; i++) {
		t->arr[i] = NULL;
	}

	return t;
}

void insert_key(trie_t *t, const char *key) {
	assert(t != NULL && "null value for the trie");
	int len = strlen(key);

	trie_t *cur_trie = t;

	for (int i = 0; i < len; i++) {
		int c = key[i] - 'a';
		if (!cur_trie->arr[c])
			cur_trie->arr[c] = create_node();

		cur_trie = cur_trie->arr[c];
	}

	cur_trie->val++;
}

int search_key(trie_t *t, const char *key) {
	assert(t != NULL && "Null trie given.");

	int len = strlen(key);

	trie_t *itr = t;
	for (int i = 0; i < len; i++) {
		int c = key[i] - 'a';
		if (!itr->arr[c]) {
			return 0;
		}
		itr = itr->arr[c];
	}

	return itr->val;
}

int destroy_trie(trie_t *t) {
	for (int i = 0; i < 26; i++) {
		if (t->arr[i])
			destroy_trie(t->arr[i]);
	}
	free(t);
	t = NULL;
	return 0;
}

void print_keys(trie_t* t, char* buff, int j){
	if(t->val){
		buff[j]='\0';
		printf("%s\n",buff);
	}
	for(int i=0; i<26; i++){
		if(t->arr[i]){
			buff[j] = 'a' + i;
			print_keys(t->arr[i],buff,j+1);
		}
	}
}