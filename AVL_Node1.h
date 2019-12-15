#ifndef AVLNODE_H_
#define AVLNODE_H_
#include <sstream>



template<typename Item_Type>
struct AVLNode {


	// Additional data field

	int right_height;

	int left_height;

	AVLNode<Item_Type>* left;
	AVLNode<Item_Type>* right;
	Item_Type data;

	// Constructor
	AVLNode(const Item_Type& the_data, AVLNode<Item_Type>* left = NULL, AVLNode<Item_Type>* right = NULL) : data(the_data), left(left), right(right), right_height(0), left_height(0) {}

	// Destructor (to avoid warning message)
	virtual ~AVLNode() {}

	int balance() { return right_height - left_height; }
	int height() {
		return right_height > left_height ? right_height : left_height;
	}

	void update_right_height() {
		if (right != NULL)
			right_height = 1 + right->height();
		else
			right_height = 0;
	}

	void update_left_height() {
		if (left != NULL)
			left_height = 1 + left->height();
		else
			left_height = 0;
	}

	// to_string
	virtual std::string to_string() const {
		std::ostringstream os;
		os << "data : " << this->data;
		return os.str();
	}
}; // End AVLNode

#endif