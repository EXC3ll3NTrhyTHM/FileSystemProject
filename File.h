#pragma once
class File {
public:
	string name;
	int size;
	File(string x, int y) {
		name = x;
		size = y;
	};
};