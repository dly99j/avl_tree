//
// Created by dly99j on 2021.09.23.
//

#include "avl_tree.h"


void balance_pp_p(std::shared_ptr<avl_node> &t, std::shared_ptr<avl_node> &r) {

    t->right = r->left;
    r->left = t;
    r->balance = 0;
    t->balance = 0;
    t = r;
}

void balance_pp_m(std::shared_ptr<avl_node> &t, std::shared_ptr<avl_node> &r) {

    auto l = r->left;
    t->right = l->left;
    r->left = l->right;
    l->left = t;
    l->right = r;
    t->balance = ((l->balance + 1) / 2) * -1;
    r->balance = ((1 - l->balance) / 2);
    l->balance = 0;
    t = l;
}

void balance_mm_p(std::shared_ptr<avl_node> &t, std::shared_ptr<avl_node> &l) {

    auto r = l->right;
    l->right = r->left;
    t->left = r->right;
    r->left = l;
    r->right = t;
    l->balance = ((r->balance + 1) / 2) * -1;
    t->balance = ((1 - r->balance) / 2);
    r->balance = 0;
    t = r;
}

void balance_mm_m(std::shared_ptr<avl_node> &t, std::shared_ptr<avl_node> &l) {

    t->left = l->right;
    l->right = t;
    l->balance = 0;
    t->balance = 0;
    t = l;
}

void left_sub_tree_grown(std::shared_ptr<avl_node> &t, bool &d) {

    if (t->balance == -1) {
        auto l = t->left;
        if (l->balance == -1) {
            balance_mm_m(t, l);
        } else {
            balance_mm_p(t, l);
        }
        d = false;
    } else {
        t->balance--;
        d = t->balance < 0;
    }
}

void right_sub_tree_grown(std::shared_ptr<avl_node> &t, bool &d) {

    if (t->balance == 1) {
        auto r = t->right;
        if (r->balance == 1) {
            balance_pp_p(t, r);
        } else {
            balance_pp_m(t, r);
        }
        d = false;
    } else {
        t->balance++;
        d = t->balance > 0;
    }
}

void avl_insert(std::shared_ptr<avl_node> &t, const T &k, bool &d) {

    if (t == nullptr) {
        t = std::make_shared<avl_node>(k);
    } else if (k < t->key) {
        avl_insert(t->left, k, d);
        if (d) {
            left_sub_tree_grown(t, d);
        }
    } else if (k > t->key) {
        avl_insert(t->right, k, d);
        if (d) {
            right_sub_tree_grown(t, d);
        }
    } else {
        d = false;
    }
}

void balance_pp_zero(std::shared_ptr<avl_node> &t, std::shared_ptr<avl_node> &r) {

    t->right = r->left;
    r->left = t;
    t->balance = 1;
    r->balance = -1;
    t = r;
}

void balance_pp(std::shared_ptr<avl_node> &t, bool &d) {

    auto r = t->right;
    switch (r->balance) {
        case -1:
            balance_pp_m(t, r);
            break;
        case 0:
            balance_pp_zero(t, r);
            break;
        case 1:
            balance_pp_p(t, r);
            break;
        default:
            throw std::runtime_error(
                    std::string("ya fucked up somewhere bud. balance is out of range at balance_pp method"));
    }
}

void left_sub_tree_shrunk(std::shared_ptr<avl_node> &t, bool &d) {

    if (t->balance == 1) {
        balance_pp(t, d);
    } else {
        t->balance++;
        d = t->balance == 0;
    }
}

void right_sub_tree_shrunk(std::shared_ptr<avl_node> &t, bool &d) {

    if (t->balance == -1) {
        balance_pp(t, d);
    } else {
        t->balance--;
        d = t->balance == 0;
    }
}

void avl_rem_min(std::shared_ptr<avl_node> &t, std::shared_ptr<avl_node> &minp, bool &d) {

    if (t->left == nullptr) {
        minp = t;
        t = minp->right;
        minp->right = nullptr;
        d = true;
    } else {
        avl_rem_min(t->left, minp, d);
        if (d) {
            left_sub_tree_shrunk(t, d);
        }
    }
}

void right_sub_tree_min_to_root(std::shared_ptr<avl_node> &t, bool &d) {

    auto p = std::make_shared<avl_node>();
    avl_rem_min(t->right, p, d);
    p->left = t->left;
    p->right = t->right;
    p->balance = t->balance;
    t = p;
}

void avl_del_root(std::shared_ptr<avl_node> &t, bool &d) {

    if (t->left == nullptr) {
        auto p = t;
        t = p->right;
        d = true;
    } else if (t->right == nullptr) {
        auto p = t;
        t = p->left;
        d = true;
    } else if (t->left == nullptr and t->right == nullptr) {
        right_sub_tree_min_to_root(t, d);
        if (d) {
            right_sub_tree_shrunk(t, d);
        }
    }
}

void avl_del(std::shared_ptr<avl_node> &t, const T &k, bool &d) {

    if (t == nullptr) {
        d = false;
    } else {
        if (k < t->key) {
            avl_del(t->left, k, d);
            if (d) {
                left_sub_tree_shrunk(t, d);
            }
        } else if (k > t->key) {
            avl_del(t->right, k, d);
            if (d) {
                right_sub_tree_shrunk(t, d);
            }
        } else if (k == t->key) {
            avl_del_root(t, d);
        }
    }
}

void inorder_print(std::shared_ptr<avl_node> &root) {

    if (root != nullptr) {
        inorder_print(root->left);
        std::cout << root->key << " ";
        inorder_print(root->right);
    }
}