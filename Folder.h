#pragma once

#include "AVL_Tree1.h"
#include "File.h"

using namespace std;

class Folder {
public:

	string name;
	int size;
	AVL_Tree<File> files;
	AVL_Tree<Folder> folders;
	void add_folder(Folder folder);
	void add_file(File file);
	void delete_folder(Folder folder);
	void delete_file(File file);
	int get_size();
	string get_name();
	Folder(string name) {
		this->name = name;
	}

	bool operator < (const Folder other) const {
		return name < other.name;
	}
	
	friend ostream& operator<<(ostream& out, const Folder& other) {
		out << other.name;
		return out;
	}

	File find_file(File file) {
		return find_file(files.get_root(), file);
	}

	// If a file is within a folder then you must provide the folder that the file is within
	File find_file(Folder folder, File file) {
		return find_file(folder.files.get_root(), file);
	}

	File find_file(AVLNode<File>* local_root, File target) {
		if (local_root == NULL) {
			File fileNull("No Files Available", 0);
			return fileNull;
		}
		if (target < local_root->data)
			return find_file(local_root->left, target);
		else if (local_root->data < target)
			return find_file(local_root->right, target);
		else
			return (local_root->data);
	}
	Folder find_folder(Folder folder) {
		return find_folder(folders.get_root(), folder);
	}

	Folder find_folder(AVLNode<Folder>* local_root, Folder target) {
		if (local_root == NULL) {
			return target;
		}
		if (target < local_root->data)
			return find_folder(local_root->left, target);
		else if (local_root->data < target)
			return find_folder(local_root->right, target);
		else
			return (local_root->data);
	}
};

// This was created so that it is more easy to accesss the size attribute of the folder
int Folder::get_size() {
	return size;
}

void Folder::add_folder(Folder folder) {
	size = size + folder.get_size();
	folders.insert(folder);
}

void Folder::add_file(File file) {
	size =  size + file.get_size();
	files.insert(file);
}

string Folder::get_name() {
	return this->name;
}

void Folder::delete_file(File file) {
	size = size - find_file(file).get_size();
	files.erase(file);
}

void Folder::delete_folder(Folder folder) {
	size = size - find_folder(folder).get_size();
	folders.erase(folder);
}