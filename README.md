custom classes:
1. Folder
Fields
- Name(string)
- Size(int)
- Files(AVL_Tree<file>)
- Folder(AVL_Tree<folder>)
Methods
- void add_folder(Folder folder)
- void delete_folder(Folder folder)
- void add_file(File file)
- File find_file(File file)
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
