#pragma once

#include <string>
#include "AVL_Tree1.h"
#include "File.h"
#include <vector>

using namespace std;

class Folder {
public:
	string name;
	int size;
	AVL_Tree<File> files;
	void add_folder(string name);
	void add_file(string name, int size);
	void delete_folder(string name);
	void delete_file(string name);
	File get_file(string name);
	AVL_Tree<File> get_files(vector<string> names);
	Folder(string x) {
		name = x;
	};
};