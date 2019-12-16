#pragma once

#include "AVL_Tree1.h"
#include "File.h"
#include <vector>

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
	File find_file(string file);
	File find_file(Folder folder, string file);
	File find_file(AVLNode<File>* local_root, string target);
	vector<File> find_files(string name);
	vector<File> find_files(string name, Folder folder);
	vector<File> find_files(string name, AVLNode<File>* local_root, vector<File> file_list);
	Folder find_folder(Folder folder);
	Folder find_folder(AVLNode<Folder>* local_root, Folder target);
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
	size = size - find_file(file.name).get_size();
	files.erase(file);
}

void Folder::delete_folder(Folder folder) {
	size = size - find_folder(folder).get_size();
	folders.erase(folder);
}

File Folder::find_file(string file) {
	return find_file(files.get_root(), file);
}

// If a file is within a folder then you must provide the folder that the file is within
File Folder::find_file(Folder folder, string file) {
	return find_file(folder.files.get_root(), file);
}

File Folder::find_file(AVLNode<File>* local_root, string target) {
	if (local_root == NULL) {
		File fileNull("File not found", 0);
		return fileNull;
	}
	if (target < local_root->data.name)
		return find_file(local_root->left, target);
	else if (local_root->data.name < target)
		return find_file(local_root->right, target);
	else
		return (local_root->data);
}

vector<File> Folder::find_files(string name) {
	vector<File> files_found;
	return find_files(name, files.get_root(), files_found);
}

vector<File> Folder::find_files(string name, Folder folder) {
	vector<File> files_found;
	return find_files(name, folder.files.get_root(), files_found);
}

vector<File> Folder::find_files(string name, AVLNode<File>* local_root, vector<File> file_list) {
	if (local_root == NULL) {
		File fileNull("File not found", 0);
		file_list.push_back(fileNull);
		return file_list;
	}
	else if (local_root->data.name.find(name) != string::npos) {
		file_list.push_back(local_root->data);
		if (local_root->left != NULL) {
			file_list = find_files(name, local_root->left, file_list);
		}
		if (local_root->right != NULL) {
			file_list = find_files(name, local_root->right, file_list);
		}
		if (local_root->left == NULL && local_root->right == NULL) {
			return file_list;
		}
		return file_list;
	}
	else if (name < local_root->data.name) {
		return find_files(name, local_root->left, file_list);
	}
	else if (local_root->data.name < name) {
		return find_files(name, local_root->right, file_list);
	}
	else {
		file_list.push_back(local_root->data);
		if (local_root->left != NULL) {
			file_list = find_files(name, local_root->left, file_list);
		}
		if (local_root->right != NULL) {
			file_list = find_files(name, local_root->right, file_list);
		}
		if (local_root->left == NULL && local_root->right == NULL) {
			return file_list;
		}
		return file_list;
	}
}

Folder Folder::find_folder(Folder folder) {
	return find_folder(folders.get_root(), folder);
}

Folder Folder::find_folder(AVLNode<Folder>* local_root, Folder target) {
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