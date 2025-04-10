#pragma once
#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
	public:
		searchable_tree_bag() = default;
		searchable_tree_bag(const searchable_tree_bag &oth) : tree_bag(oth) {}
		searchable_tree_bag &operator=(const searchable_tree_bag &other) {
			if (this != &other) {
				tree_bag::operator=(other);
			}
			return *this;
		}
	~searchable_tree_bag() = default;

	bool	has(int val) const {
		node *current = tree;
		while (current) {
			if (current->value == val)
				return true;
			else if (val > current->value)
				current = current->r;
			else
				current = current->l;
		}
		return false;
	}
};