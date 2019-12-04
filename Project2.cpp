// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Folder.h"

int main()
{
	Folder folder1("Animals");
	File file1("Hippo", 34);
	File file2("Mouse", 3);

	cout << folder1.get_name();

	folder1.add_file(file1);

	cout << folder1.get_size();
	folder1.add_file(file2);
	cout << folder1.get_size();
}