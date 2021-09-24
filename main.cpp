#include <iostream>
#include "avl_tree.h"

int main() {
    std::shared_ptr<avl_node> root;
    bool d;

    avl_insert(root, 10, d);
    avl_insert(root, 15, d);
    avl_insert(root, 0, d);
    avl_insert(root, 110, d);
    avl_insert(root, 34, d);
    avl_insert(root, 56, d);
    avl_insert(root, 78, d);
    avl_insert(root, 53, d);
    avl_insert(root, 85, d);
    avl_insert(root, 11, d);
    avl_insert(root, 7, d);

    std::cout << root->key << std::endl;

    inorder_print(root);

    std::cout << std::endl;

    preorder_print(root);

}
