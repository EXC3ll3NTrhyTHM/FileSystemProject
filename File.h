#pragma once

#include <string>

using namespace std;

class File {
public:
	string name;
	int size;
	File(string name, int size) {
		this->name = name;
		this->size = size;
	}
	int get_size() {
		return this->size;
	}

	string get_name() {
		return this->name;
	}

	bool operator < (const File other) const {
		return name < other.name;
	}

	friend ostream& operator<<(ostream& out, const File& other) {

		out << other.name;
		return out;
	}
};