#include "bst.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    bst *tree = new_bst();
    printf("%p",tree);
//    delete_bst(tree);
}