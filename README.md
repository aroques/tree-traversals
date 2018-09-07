# Tree Traversals

Pre, post, and inorder traversal operations on a binary search tree. Each node's key is a character and holds a list of strings that begin with that character.

## Usage

To build the project run:
```
make
```

To run the project you must provide strings that the program can use to build a binary search tree with. There are 3 ways to do this:  
1. Provide a text file that contains strings. The file should have the extension `.fs182`.
```
p0 filename
```    
2. Provide the text file to stdin using redirection:
```
p0 < filename.fs182
```    
3. Or, provide strings via the keyboard (stdin) and press ctrl-d to enter the EOF character when done: 
```
p0 
```    
