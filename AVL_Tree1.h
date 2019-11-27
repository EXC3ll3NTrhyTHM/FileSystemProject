#ifndef AVL_TREE_H
#define AVL_TREE_H


#include "AVL_Node1.h"

template<typename Item_Type>
class AVL_Tree {
public:

	AVL_Tree() : root(NULL) {
	}


	AVL_Tree(const Item_Type& the_data, const AVL_Tree<Item_Type>& left_child = AVL_Tree(),
		const AVL_Tree<Item_Type>& right_child = AVL_Tree()) :
		root(new AVLNode<Item_Type>(the_data, left_child.root,
			right_child.root)) {}

	/** Return the left-subtree */
	AVL_Tree<Item_Type> get_left_subtree() const {
		if (root == NULL) {
			throw std::invalid_argument("get_left_subtree on empty tree");
		}
		return AVL_Tree<Item_Type>(root->left);
	}


	/** Return the right-subtree */
	AVL_Tree<Item_Type> get_right_subtree() const {
		if (root == NULL) {
			throw std::invalid_argument("get_right_subtree on null tree");
		}
		return AVL_Tree<Item_Type>(root->right);
	}

	/** Return the data field of the root
	@throws std::invalid_argument if null tree
	*/

	const Item_Type& AVL_Tree<Item_Type>::get_data() const {
		if (root == NULL) {
			throw std::invalid_argument("get_data on null tree");
		}
		return root->data;
	}

	bool is_null() const {
		return root == NULL;
	}

	/** Indicate that this tree is a leaf. */
	bool is_leaf() const {
		if (root != NULL) {
			return root->left == NULL && root->right == NULL;
		}
		else
			return true;
	}


	virtual bool insert(const Item_Type& item) {
		return insert(this->root, item);
	}

	bool erase(const Item_Type& item) {
		return erase(this->root, item);
	}

	Item_Type& find(const Item_Type& item) const {
		return find(this->root, item);
	}




protected:

	AVLNode<Item_Type>* root;

	AVL_Tree(AVLNode<Item_Type>* new_root) : root(new_root) {}

	Item_Type& find(AVLNode<Item_Type>* local_root, const Item_Type& target) const {
		if (local_root == NULL) {
			Item_Type item;
			return item;
		}
		if (target < local_root->data)
			return find(local_root->left, target);
		else if (local_root->data < target)
			return find(local_root->right, target);
		else
			return (local_root->data);
	}

	bool erase(AVLNode<Item_Type>*& local_root, const Item_Type& item) {
		if (local_root == NULL) {
			return false;
		}
		else {
			if (item < local_root->data) {
				bool return_value = erase(local_root->left, item);
				if (return_value) {
					adjust_balance(local_root);
					rebalance(local_root);
				}
				return return_value;
			}
			else if (local_root->data < item) {
				bool return_value = erase(local_root->right, item);
				if (return_value) {
					adjust_balance(local_root);
					rebalance(local_root);
				}
				return return_value;
			}
			else {
				AVLNode<Item_Type>* old_root = local_root;

				if (local_root->left == NULL)
					local_root = local_root->right;
				else if (local_root->right == NULL)
					local_root = local_root->left;
				else
					replace_parent(old_root, old_root->left);

				if (local_root != NULL) {
					adjust_balance(local_root);
					rebalance(local_root);
				}

				delete old_root;
				return true;
			}
		}
	}

	void rebalance(AVLNode<Item_Type>*& local_root) {
		if (local_root->balance() <= -2)
			rebalance_left(local_root);
		else if (local_root->balance() >= 2)
			rebalance_right(local_root);
	}


	void adjust_balance(AVLNode<Item_Type>*& node) {
		node->update_left_height();
		node->update_right_height();
	}

	void replace_parent(AVLNode<Item_Type>*& old_root, AVLNode<Item_Type>*& local_root) {
		if (local_root->right != NULL) {
			replace_parent(old_root, local_root->right);
			adjust_balance(local_root);
			rebalance(local_root);
		}
		else {
			old_root->data = local_root->data;
			old_root = local_root;
			if (local_root->left != NULL) {
				local_root = local_root->left;
				adjust_balance(local_root);
			}
			else
				local_root = NULL;
		}
	}


	bool insert(AVLNode<Item_Type>*& local_root, const Item_Type& item) {
		if (local_root == NULL) {
			local_root = new AVLNode<Item_Type>(item);
			return true;
		}
		else {
			if (item < local_root->data) {
				bool return_value = insert(local_root->left, item);
				if (return_value) { //we have inserted the item
					local_root->update_left_height(); //left height might increase by 1

					if (local_root->balance() <= -2) // local root is now critically unbalanced
						rebalance_left(local_root);
				}
				return return_value;
			}
			else if (local_root->data < item) {
				bool return_value = insert(local_root->right, item);

				if (return_value) {
					local_root->update_right_height(); //right height might increase by 1

					if (local_root->balance() >= 2) // local root is now critically unbalanced
						rebalance_right(local_root);
				}
				return return_value;
			}
			else
				return false; //item already exists
		}
	}


	void rebalance_left(AVLNode<Item_Type>*& local_root) {

		if (local_root->left->balance() > 0)  // See whether left-right-heavy
			rotate_left(local_root->left); // Perform left rotation

		// Finally rotate right
		rotate_right(local_root);
	}

	void rebalance_right(AVLNode<Item_Type>*& local_root) {

		if (local_root->right->balance() < 0)  // See whether right-left-heavy
			rotate_right(local_root->right); // Perform left rotation

		// Finally rotate right
		rotate_left(local_root);
	}

	void rotate_right(AVLNode<Item_Type>*& local_root) {
		AVLNode<Item_Type>* temp = local_root->left;
		local_root->left = temp->right;

		//adjust the balances
		local_root->update_left_height();

		temp->right = local_root;

		temp->update_right_height();

		local_root = temp;
	}

	void rotate_left(AVLNode<Item_Type>*& local_root) {
		AVLNode<Item_Type>* temp = local_root->right;
		local_root->right = temp->left;

		//adjust the balances
		local_root->update_right_height();

		temp->left = local_root;

		temp->update_left_height();

		local_root = temp;
	}



};

#endif