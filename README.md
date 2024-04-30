IDEATHON 
Project Title: Data Structures 
Visualization 
 
This code is an implementation of three different types of tree data structures: 
AVL Trees, Binary Search Trees, and B-Trees. It provides functionality to insert, 
delete, and traverse the trees, as well as print their structure.  
1. AVL Tree: 
  The AVL Tree implementation includes functions to create a new node 
(newNode), insert a node (insert), delete a node (deleteNode), perform inorder 
traversal (inorder), and print the tree structure (printTree). 
➢ The key operations are insert, deleteNode, inorder and printTree. 
➢ AVL Trees are self-balancing binary search trees that maintain a balanced 
structure by performing rotations during insertions and deletions. 
➢ The height of an AVL Tree is bounded by approximately 1.44 log(n), where 
n is the number of nodes, ensuring efficient operations with O(log n) time 
complexity for insertion, deletion, and search. 
➢ The code implements the necessary helper functions like max, height, 
newNode, rightRotate, leftRotate, getBalance, and minValueNode to 
support the AVL Tree operations. 
 
2. Binary Search Tree: 
➢ The Binary Search Tree implementation includes functions to create a 
new node (createNode), insert a node (insertBinaryNode), delete a 
node (deleteBinaryNode), perform inorder traversal 
(binaryInorderTraversal), and print the tree structure (printBinaryTree). 
➢ The key operations are insertBinaryNode, deleteBinaryNode, 
binaryInorderTraversal, and printBinaryTree. 
➢ Binary Search Trees are simple binary trees where the value of each 
node is greater than all the values in the left subtree and less than all 
the values in the right subtree. 
➢ Operations like insertion, deletion, and search have an average time 
complexity of O(log n), but the worst-case scenario can be O(n) if the 
tree becomes skewed. 
➢  The code includes helper functions like minBinaryValueNode and 
binaryTreeHeight to support the Binary Search Tree operations. 
 Example: Binary Tree structure after inserting the keys 10, 20, 30, 40, 50, 25: 
 
                    30 
                  /    \ 
                20      40 
              /   \      \ 
             10   25     50 
 
3. B-Tree: 
➢ The B-Tree implementation includes functions to create a new node 
(btree_create_node), insert a node (btree_insert), delete a node 
(btree_delete_node), perform inorder traversal 
(btree_inorder_traversal), and print the tree structure (printBTree). 
➢ The key operations are btree_insert, btree_delete_node, 
btree_inorder_traversal, and printBTree. 
➢ B-Trees are self-balancing tree data structures that maintain sorted 
data and allow efficient insertion, deletion, and search operations. 
➢ Each node in a B-Tree can have more than one key and more than two 
child nodes, allowing for a higher branching factor compared to binary 
trees. 
➢ The time complexity for insertion, deletion, and search operations in a 
B-Tree is O(log n), where n is the number of keys stored in the tree. 
➢ The code implements helper functions like btree_split_child, 
btree_insert_non_full, btree_search, btree_delete_from_leaf, 
btree_delete_from_non_leaf, and btreeHeight to support the B-Tree 
operations. 
 
The code also includes a main function that provides a command-line interface 
for the user to interact with the three tree data structures. The user can choose 
which tree structure to work with and perform various operations like 
insertion, deletion, traversal, and printing the tree structure. 
Example of how the AVL Tree structure might look like after inserting the keys 
10, 20, 30, 40, 50, 25 
 
                    30 
                  /    \ 
                20      40 
              /    \      \ 
             10    25     50 
 
Example of how the B-Tree structure might look like after inserting the keys 10, 
20, 30, 40, 50, 60, 70 
                    [30, 50, 70] 
                  /   |    |     \ 
        [10, 20]     [40]  [60]   [] 
 
1. Error Handling: The code currently uses exit(EXIT_FAILURE) to handle 
memory allocation failures. It would be better to use proper error handling 
mechanisms and gracefully handle such errors. 
 
2. Memory Management: The code should ensure proper memory 
deallocation for all dynamically allocated nodes and structures when they are 
no longer needed. 
3. Function Documentation: Adding comments to explain the 
purpose, input parameters, and return values of each function would 
improve code readability and maintainability. 
4. Additional Functionality: Depending on the requirements, additional 
functionality like searching for a key, balancing the trees, or implementing 
other traversal methods (preorder, postorder) could be added. 
5.Testing: Implementing comprehensive unit tests to ensure the correctness 
of the tree operations would be beneficial for maintaining and extending the 
code. 
This code demonstrates a solid understanding of tree data structures and their 
implementation. With the suggested improvements, the code can become 
more robust, maintainable, and user-friendly.

HOW to implement:
1. Copy and Paste on your code editor
2. Utilise user interface on terminal
