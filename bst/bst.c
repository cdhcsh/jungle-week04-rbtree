#include "bst.h"

#include <stdlib.h>

bst *new_bst(void) {
  bst *p = (bst *)calloc(1, sizeof(bst));
  return p;
}

void delete_bst(bst *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *bst_insert(bst *t, const key_t key) {
  // TODO: implement insert
  return t->root;
}

node_t *bst_find(const bst *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *bst_min(const bst *t) {
  // TODO: implement find
  return t->root;
}

node_t *bst_max(const bst *t) {
  // TODO: implement find
  return t->root;
}

int bst_erase(bst *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int bst_to_array(const bst *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
