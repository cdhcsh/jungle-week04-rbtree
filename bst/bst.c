#include "bst.h"

#include <stdlib.h>
#include <stdio.h>

static node_t *_insert(node_t *t, const key_t key);
static node_t *_find(const node_t *t, const key_t key);
static node_t *_min(const node_t *t);
static node_t *_max(const node_t *t);
static void _delete_node(node_t *t);
static node_t *_erase_node(const node_t *t);
static node_t **_find_parent(const node_t *t, const node_t *c);
static void _traverse(const node_t *t);

bst *new_bst(void) {
    bst *p = (bst *) calloc(1, sizeof(bst));
    return p;
}

void delete_bst(bst *t) {
    _delete_node(t->root);
    free(t);
}

static void _delete_node(node_t *t){
    if (t == NULL) {
        return;
    }
    if (t->left == NULL && t->right == NULL) {
        free(t);
        return;
    }
    _delete_node(t->left);
    _delete_node(t->right);
    free(t);
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
        if (node == NULL){
            return NULL;
        }
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
    node_t **parent = _find_parent(t->root, p);
    if (parent != NULL) { //부모 노드가 있다면
        *parent = _erase_node(p); // 삭제할 노드의 부모노드의 자식을 변경
    }
    if (p != t->root){ // 부모 노드가 없고, 루트가 아님 (트리에 없는 노드)
        return 1;
    }
    free(p);
    return 0;
}

static node_t *_erase_node(const node_t *t){
    if (t->left == NULL && t->right == NULL){
        return NULL;
    }
    if (t->left != NULL && t->right == NULL){
        return t->left;
    }
    if (t->left == NULL){
        return t->right;
    }
    node_t *d = _min(t->right); //오른쪽 서브트리의 최소값을 가진 노드 가져옴
    *(_find_parent(t,d))=NULL; // 교체할 노드와 그 부모 노드와의 연결 끊기
    d->left = t->left; // 삭제할 노드의 연결된 자식 노드 정보를 교체할 노드에 저장
    d->right = t->right;
    return d;
}

static node_t **_find_parent(const node_t *root, const node_t *t) {
    if (root == NULL || t == NULL) {
        return NULL;
    }
    if (root->left == t) {
        return (node_t **) (&root->left);
    }
    if (root->right == t) {
        return (node_t **) (&root->right);
    }
    node_t **p = NULL;
    if (root->left != NULL) {
        p = _find_parent(root->left, t);
    }
    if (p == NULL && root->right != NULL) {
        p = _find_parent(root->right, t);
    }
    return p;

}

int bst_to_array(const bst *t, key_t *arr, const size_t n) {
    _traverse(t->root);
    printf("\n");
    return 0;
}
static void _traverse(const node_t *t){
    if(t == NULL){
        return;
    }
    _traverse(t->left);
    printf("%d", t->key);
    _traverse(t->right);

}


