//
// Created by dly99j on 2021.09.23.
//

#ifndef UNTITLED_AVL_TREE_HPP
#define UNTITLED_AVL_TREE_HPP

#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>

using T = int; //any value that has comparison operators defined

struct avl_node {
	T key;
	int balance = 0;
	std::shared_ptr<avl_node> left{ nullptr };
	std::shared_ptr<avl_node> right{ nullptr };

	explicit avl_node(const T& t_key) : key(t_key) {}
	avl_node() = default;
};

void balance_pp_p(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& r);
void balance_pp_m(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& r);
void balance_mm_p(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& l);
void balance_mm_m(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& l);

void left_sub_tree_grown(std::shared_ptr<avl_node>& t, bool& d);
void right_sub_tree_grown(std::shared_ptr<avl_node>& t, bool& d);

void avl_insert(std::shared_ptr<avl_node>& t, const T& k, bool& d);

void balance_pp_zero(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& r);
void balance_pp(std::shared_ptr<avl_node>& t, bool& d);

void left_sub_tree_shrunk(std::shared_ptr<avl_node>& t, bool& d);
void right_sub_tree_shrunk(std::shared_ptr<avl_node>& t, bool& d);

void avl_rem_min(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& minp, bool& d);

void right_sub_tree_min_to_root(std::shared_ptr<avl_node>& t, bool& d);

void avl_del_root(std::shared_ptr<avl_node>& t, bool& d);

void avl_del(std::shared_ptr<avl_node>& t, const T& k, bool& d);

void avl_find(std::shared_ptr<avl_node>& t, std::shared_ptr<avl_node>& res, const T& k, bool& d);

void inorder_print(std::shared_ptr<avl_node>& root);



#endif //UNTITLED_AVL_TREE_HPP
