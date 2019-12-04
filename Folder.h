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
	void delete_folder(string name);
	void delete_file(string name);
	File get_file(string name);
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