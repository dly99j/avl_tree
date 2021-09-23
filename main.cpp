#include <iostream>
#include "avl_tree.h"

int main() {
	auto root = std::make_shared<avl_node>(20);
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

	inorder_print(root);
	std::cout << std::endl << std::endl;

    avl_del(root, 34, d);
    avl_del(root, 0, d);
    avl_del(root, 78, d);
    avl_del(root, 7, d);

    inorder_print(root);
    std::cout << std::endl << std::endl;

    auto p = std::make_shared<avl_node>();
    avl_rem_min(root, p, d);

    std::cout << p->key << std::endl;
    std::cout << std::endl << std::endl;

    inorder_print(root);
    std::cout << std::endl << std::endl;
}
