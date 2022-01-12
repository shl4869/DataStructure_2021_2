huffman_Readme.txt

//Program Purpose
This program is written for making the codeword for the given characters, encoding the given string, and decoding it again. 

1. typedef

(1) TreeNode:
the structure contains the character(char data), frequency of the data(int key), Huffman codeword and its size, and the addresses of left and right child of the node.

(2) bits_stream:
the structure contains the bit stream which represents the encoded string, and the length of the stream. 


2. Functions

(1) void huffman_traversal(TreeNode *node,int digit,int code):
This function is made for making the code word for each characer. When the Huffman tree is given, the function travels tree by recursively calling itself and assigning the codeword for each node. When the node is a leaf, it assigns a codeword for a character of the node and adds it to the row of 'm_LUT'.
There is no return for this function.

(2) void huffman_encoding(char *str, bits_stream *bits_str):
This function is for encoding the given string. When it reads a character from the string(char *str), the code word in ‘m_LUT’ is copied to the bit stream. ‘int wtcode’ indicates which index to start writing. When writing is over, the size of codeword is added to the length of the bit stream. When this operates within all characters in the string, it prints out the length of bit stream and the actual bit stream. 
There is no return for this function.

(3) int huffman_decoding(bits_stream *bits_str, TreeNode *node, char *decoded_str):
This function is for decoding the given bit stream. The outermost while statement loops until the reading of the code is over. Inside of the second while loop, ‘tnode’ is updated following the address of Huffman tree given and as the function reads bits of the stream. When it meets the leaf node, it adds ‘char data’ of ‘tnode’ to the decoded string. When all the loop is over, it prints out the number of decoded characters and the decoded string. 
This function has no return