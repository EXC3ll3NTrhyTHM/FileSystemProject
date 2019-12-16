// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Folder.h"

int main()
{
	Folder animals("Animals");
	Folder mammals("Mammals");
	Folder reptiles("Reptiles");
	File lizard("Lizard", 4);
	File dragon("Lizard2", 67);
	File hippo("Hippo", 34);
	File mouse("Mouse", 3);
	File human("Human", 18);
	File human2("Human2", 35);
	File human3("Human3", 35);
	File human4("Human4", 35);
	File human5("Human5", 35);
	File human6("Human6", 35);

	// Test for add_file method
	mammals.add_file(hippo);
	reptiles.add_file(lizard);
	reptiles.add_file(dragon);

	cout << mammals.get_size() << endl;
	cout << reptiles.get_size() << endl;

	mammals.add_file(mouse);

	cout << mammals.get_size() << endl;

	// Test for find_file method
	cout << mammals.find_file("Hippo") << endl;
	cout << reptiles.find_file("Lizard") << endl;

	// Test for delete_file method
	mammals.delete_file(mouse);

	cout << mammals.get_size() << endl;

	// Test for add_folder method
	animals.add_folder(mammals);
	animals.add_folder(reptiles);
	animals.add_file(human);

	// Test for find_file method for file inside of folder
	cout << animals.find_file(mammals, "Hippo") << endl;
	cout << animals.find_file(reptiles, "Lizard") << endl;
	cout << animals.find_file("Human") << endl;
	cout << animals.find_file("Human") << endl;
	// The test below is testing the file not found result. The folder is not provided so the file cannot be foundS
	cout << animals.find_file("Hippo") << endl;
	cout << animals.get_size() << endl;

	// Test for find_files method
	animals.add_file(human2);
	animals.add_file(human3);
	animals.add_file(human4);
	animals.add_file(human5);
	animals.add_file(human6);
	vector<File> found_files = animals.find_files("Human");
	for (int i = 0; i < found_files.size(); i++) {
		cout << found_files[i] << endl;
	}

	// Searching for a file within a folder within a folder. Path: Animals/Reptiles/
	found_files = animals.find_files("Lizard", reptiles);
	for (int i = 0; i < found_files.size(); i++) {
		cout << found_files[i] << endl;
	}
}