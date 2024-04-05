#include "bst.h"
#include "stdio.h"
#include "assert.h"

void test_init() {
    bst *tree = new_bst();
    assert(tree != NULL);
    assert(tree->root == NULL);
    delete_bst(tree);
}
void test_insert(const key_t key) {
    bst *tree = new_bst();
    node_t *p = bst_insert(tree, key);
    assert(p != NULL);
    assert(tree->root == p);
    assert(p->key == key);
    delete_bst(tree);
}

void test_find(const key_t key, const key_t wrong_key) {
    bst *tree = new_bst();
    bst_insert(tree, key);
    node_t *p = bst_find(tree, key);
    assert(p->key == key);
    p = bst_find(tree, wrong_key);
    assert(p == NULL);
    delete_bst(tree);
}

void test_minmax(const key_t min_key, const key_t max_key) {
    bst *tree = new_bst();
    bst_insert(tree, min_key);
    bst_insert(tree, max_key);
    node_t *p = bst_min(tree);
    assert(p->key == min_key);
    p = bst_max(tree);
    assert(p->key == max_key);
    delete_bst(tree);
}

int main(int argc, char *argv[]) {
    test_init();
    test_insert(1024);
    test_find(1024, 512);
    test_minmax(1, 2);
    printf("success!\n");
    return 0;
}