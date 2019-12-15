custom classes:
1. Folder
Fields
- Name(string)
- Size(int)
- Files(AVL_Tree<file>)
Methods
- void add_folder(string path, string folder_name)
- void delete_folder(string path, string folder_name)
- void add_file(string path, string file_name, int size)
- File get_file(string path, string file_name)
- list<File> get_files(string path, string file_name)
Class constructor for folder class

2. File
Fields
- Name (string)
- Size (int)
Class constructor for file class

Constraints:
- have to mainly self-balancing binary search tree
- AVL_Tree
- dont need menu based interaction/can use main function to test project
