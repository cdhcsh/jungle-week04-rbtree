#include "bst.h"

#include <stdlib.h>

static node_t *_insert(node_t *t, const key_t key);

static node_t *_find(const node_t *t, const key_t key);

static node_t *_min(const node_t *t);

static node_t *_max(const node_t *t);

bst *new_bst(void) {
    bst *p = (bst *) calloc(1, sizeof(bst));
//  *p->root = NULL
    return p;
}

void delete_bst(bst *t) {

    free(t);
}

static void _delete_node(node_t *t) {
    if (t->left == NULL && t->right == NULL) {
        free(t);
        return;
    }
    if (t->left != NULL) {
        _delete_node(t->left);
    }
    if (t->right != NULL) {
        _delete_node(t->right);
    }
}

node_t *bst_insert(bst *t, const key_t key) {
    if (t->root == NULL) {
        return t->root = _insert(t->root, key);
    } else {
        return _insert(t->root, key);
    }
}

static node_t *_insert(node_t *t, const key_t key) {
    if (t == NULL) {
        node_t *node = (node_t *) calloc(1, sizeof(node_t));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else {
        if (t->key > key) {
            t->left = _insert(t->left, key);
        } else if (t->key < key) {
            t->right = _insert(t->right, key);
        }
        return t;
    }
}

node_t *bst_find(const bst *t, const key_t key) {
    return _find(t->root, key);
}

static node_t *_find(const node_t *t, const key_t key) {
    if (t == NULL) {
        return NULL;
    } else {
        if (t->key == key) {
            return (node_t *) t;
        } else if (t->key > key) {
            return _find(t->left, key);
        } else {
            return _find(t->right, key);
        }
    }
}

node_t *bst_min(const bst *t) {
    return _min(t->root);
}

static node_t *_min(const node_t *t) {
    if (t == NULL) {
        return NULL;
    } else if (t->left == NULL) {
        return (node_t *) t;
    } else {
        return _min(t->left);
    }
}

node_t *bst_max(const bst *t) {
    return _max(t->root);
}

static node_t *_max(const node_t *t) {
    if (t == NULL) {
        return NULL;
    } else if (t->right == NULL) {
        return (node_t *) t;
    } else {
        return _max(t->right);
    }
}

int bst_erase(bst *t, node_t *p) {
//    if (p->left == NULL && p->right == NULL){
//        free(p);
//    }
    return 0;
}

int bst_to_array(const bst *t, key_t *arr, const size_t n) {
    // TODO: implement to_array
    return 0;
}
