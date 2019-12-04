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
	File hippo("Hippo", 34);
	File mouse("Mouse", 3);
	File human("Human", 18);

	// Test for add_file method
	mammals.add_file(hippo);
	reptiles.add_file(lizard);

	cout << mammals.get_size() << endl;
	cout << reptiles.get_size() << endl;

	mammals.add_file(mouse);

	cout << mammals.get_size() << endl;

	// Test for find_file method
	cout << mammals.find_file(hippo) << endl;
	cout << reptiles.find_file(lizard) << endl;

	// Test for delete_file method
	mammals.delete_file(mouse);

	cout << mammals.get_size() << endl;

	// Test for add_folder method
	animals.add_folder(mammals);
	animals.add_folder(reptiles);
	animals.add_file(human);

	// Test for find_file method for file inside of folder
	cout << animals.find_file(mammals, hippo) << endl;
	cout << animals.find_file(reptiles, lizard) << endl;
	cout << animals.find_file(human) << endl;
	cout << animals.get_size() << endl;
}