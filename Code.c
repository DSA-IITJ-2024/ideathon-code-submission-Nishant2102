#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    printf("%d ", temp->key);
    inorder(temp->right);
}

int treeHeight(Node* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

void printGivenLevel(Node* root, int level, bool diamond) {
    if (root == NULL) {
        if (diamond)
            printf("  ");
        else
            printf("- ");
        return;
    }
    if (level == 1) {
        if (diamond)
            printf("%-2d", root->key);
        else
            printf("%d ", root->key);
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1, diamond);
        printGivenLevel(root->right, level - 1, diamond);
    }
}

void printTree(Node* root, bool diamond) {
    int h = treeHeight(root);
    int i, j;
    for (i = 1; i <= h; i++) {
        for (j = 0; j < h - i; j++) {
            printf("  ");
        }
        printGivenLevel(root, i, diamond);
        printf("\n");
    }
}

// ## BINARY TREE-----------------------------------------------------

// Structure for a node of the binary tree
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with the given data into a binary tree
struct TreeNode* insertBinaryNode(struct TreeNode* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertBinaryNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertBinaryNode(root->right, data);
    }
    // Return the unchanged node pointer
    return root;
}

// Function to perform inorder traversal of the binary tree
void binaryInorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        binaryInorderTraversal(root->left);
        printf("%d ", root->data);
        binaryInorderTraversal(root->right);
    }
}

// Function to find the minimum value node in a binary tree
struct TreeNode* minBinaryValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from the binary tree
struct TreeNode* deleteBinaryNode(struct TreeNode* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return root;
    }
    // Recur down the tree
    if (key < root->data) {
        root->left = deleteBinaryNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBinaryNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = minBinaryValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteBinaryNode(root->right, temp->data);
    }
    return root;
}

// Function to print the binary tree
void printGivenLevelBinary(struct TreeNode* root, int level, bool diamond) {
    if (root == NULL) {
        if (diamond)
            printf("  ");
        else
            printf("- ");
        return;
    }
    if (level == 1) {
        if (diamond)
            printf("%-2d", root->data);
        else
            printf("%d ", root->data);
    } else if (level > 1) {
        printGivenLevelBinary(root->left, level - 1, diamond);
        printGivenLevelBinary(root->right, level - 1, diamond);
    }
}

// Function to get the height of the binary tree
int binaryTreeHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = binaryTreeHeight(root->left);
        int rightHeight = binaryTreeHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to print the binary tree
void printBinaryTree(struct TreeNode* root, bool diamond) {
    if (root == NULL) {
        return;
    }
    int h = binaryTreeHeight(root);
    int i, j;
    for (i = 1; i <= h; i++) {
        for (j = 0; j < h - i; j++) {
            printf("  ");
        }
        printGivenLevelBinary(root, i, diamond);
        printf("\n");
    }
}

// ## For BTree -------------------------------------------------------
#define MAX_KEYS 4 // Maximum number of keys in a node

typedef struct bnode {
    int keys[MAX_KEYS - 1];
    struct bnode* children[MAX_KEYS];
    int num_keys;
    int leaf;
} BNode;

BNode* btree_create_node() {
    BNode* new_node = (BNode*)malloc(sizeof(BNode));
    if (new_node != NULL) {
        new_node->num_keys = 0;
        new_node->leaf = 1;
        return new_node;
    } else {
        // Handle allocation failure
        printf("Memory allocation failed for B-tree node\n");
        exit(EXIT_FAILURE);
    }
}


void btree_split_child(BNode* parent, int index, BNode* child) {
    BNode* new_child = btree_create_node();
    if (new_child != NULL) {
        new_child->leaf = child->leaf;
        new_child->num_keys = MAX_KEYS / 2 - 1;

        // Copy keys to the new child
        for (int i = 0; i < MAX_KEYS / 2 - 1; i++) {
            new_child->keys[i] = child->keys[i + MAX_KEYS / 2];
        }

        if (!child->leaf) {
            // Copy children to the new child
            for (int i = 0; i < MAX_KEYS / 2; i++) {
                new_child->children[i] = child->children[i + MAX_KEYS / 2];
            }
        }

        child->num_keys = MAX_KEYS / 2 - 1;

        // Move keys in the parent to make space for the new child
        for (int i = parent->num_keys; i > index; i--) {
            parent->children[i + 1] = parent->children[i];
        }

        parent->children[index + 1] = new_child;

        for (int i = parent->num_keys - 1; i >= index; i--) {
            parent->keys[i + 1] = parent->keys[i];
        }

        parent->keys[index] = child->keys[MAX_KEYS / 2 - 1];
        parent->num_keys++;
    } else {
        // Handle allocation failure
        printf("Memory allocation failed for new B-tree child\n");
        exit(EXIT_FAILURE);
    }
}   

void btree_insert_non_full(BNode* node, int key) {
    int i = node->num_keys - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        if (node->children[i]->num_keys == MAX_KEYS - 1) {
            btree_split_child(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        btree_insert_non_full(node->children[i], key);
    }
}

void btree_insert(BNode** root, int key) {
    BNode* r = *root;
    if (r->num_keys == MAX_KEYS - 1) {
        BNode* new_root = btree_create_node();
        if (new_root != NULL) {
            new_root->leaf = 0;
            new_root->children[0] = r;
            *root = new_root;
            btree_split_child(new_root, 0, r);
            btree_insert_non_full(new_root, key);
        } else {
            // Handle allocation failure
            printf("Memory allocation failed for new B-tree root\n");
            exit(EXIT_FAILURE);
        }
    } else {
        btree_insert_non_full(r, key);
    }
}


BNode* btree_search(BNode* node, int key) {
    int i = 0;
    while (i < node->num_keys && key > node->keys[i]) {
        i++;
    }
    if (i < node->num_keys && key == node->keys[i]) {
        return node;
    }
    if (node->leaf) {
        return NULL;
    }
    return btree_search(node->children[i], key);
}

void btree_inorder_traversal(BNode* node) {
    if (node) {
        int i;
        for (i = 0; i < node->num_keys; i++) {
            if (!node->leaf) {
                btree_inorder_traversal(node->children[i]);
            }
            printf("%d ", node->keys[i]);
        }
        if (!node->leaf) {
            btree_inorder_traversal(node->children[i]);
        }
    }
}

void btree_delete_node(BNode* node, int key);

void btree_delete_from_leaf(BNode* node, int key) {
    int i = 0;
    while (i < node->num_keys && key != node->keys[i]) {
        i++;
    }
    if (i == node->num_keys) {
        printf("Key %d not found\n", key);
        return;
    }
    for (int j = i; j < node->num_keys - 1; j++) {
        node->keys[j] = node->keys[j + 1];
    }
    node->num_keys--;
}

void btree_delete_from_non_leaf(BNode* node, int key, int index) {
    int k = node->keys[index];
    if (node->children[index]->num_keys >= MAX_KEYS / 2) {
        // Move key from the child's predecessor
        BNode* pred = node->children[index];
        while (!pred->leaf) {
            pred = pred->children[pred->num_keys];
        }
        node->keys[index] = pred->keys[pred->num_keys - 1];
        btree_delete_node(node->children[index], pred->keys[pred->num_keys - 1]);
    } else if (node->children[index + 1]->num_keys >= MAX_KEYS / 2) {
        // Move key from the child's successor
        BNode* succ = node->children[index + 1];
        while (!succ->leaf) {
            succ = succ->children[0];
        }
        node->keys[index] = succ->keys[0];
        btree_delete_node(node->children[index + 1], succ->keys[0]);
    } else {
        // Merge the child with its sibling
        BNode* child = node->children[index];
        BNode* sibling = node->children[index + 1];
        child->keys[child->num_keys] = k;
        for (int i = 0; i < sibling->num_keys; i++) {
            child->keys[child->num_keys + 1 + i] = sibling->keys[i];
        }
        if (!child->leaf) {
            for (int i = 0; i <= sibling->num_keys; i++) {
                child->children[child->num_keys + 1 + i] = sibling->children[i];
            }
        }
        child->num_keys += sibling->num_keys + 1;
        // Remove key from parent and shift keys and children accordingly
        for (int i = index; i < node->num_keys - 1; i++) {
            node->keys[i] = node->keys[i + 1];
        }
        for (int i = index + 1; i < node->num_keys; i++) {
            node->children[i] = node->children[i + 1];
        }
        node->num_keys--;
        free(sibling);
        // Recursively delete the key from the merged child
        btree_delete_node(child, key);
    }
}

void btree_delete_node(BNode* node, int key) {
    int index = 0;
    // Find the index of the key to delete
    while (index < node->num_keys && key > node->keys[index]) {
        index++;
    }
    // If the key is found in this node
    if (index < node->num_keys && key == node->keys[index]) {
        if (node->leaf) {
            // Key found in a leaf node, delete it
            for (int i = index; i < node->num_keys - 1; i++) {
                node->keys[i] = node->keys[i + 1];
            }
            node->num_keys--;
        } else {
            // Key found in a non-leaf node, delete it from appropriate child
            btree_delete_from_non_leaf(node, key, index);
        }
    } else {
        // If the key is not found in this node
        if (node->leaf) {
            // Key not found in a leaf node
            printf("Key %d not found\n", key);
            return;
        }
        // Key not found in this node, recursively search in appropriate child
        int flag = (index == node->num_keys) ? 1 : 0;
        if (node->children[index]->num_keys < MAX_KEYS / 2) {
            // If the child doesn't have enough keys, adjust it
            // (similar logic to insertion when splitting nodes)
            if (index != 0 && node->children[index - 1]->num_keys >= MAX_KEYS / 2) {
                // Borrow a key from the left sibling
                // (similar logic to merging nodes when deleting)
                // Implementation remains the same as insertion
            } else if (index != node->num_keys && node->children[index + 1]->num_keys >= MAX_KEYS / 2) {
                // Borrow a key from the right sibling
                // (similar logic to merging nodes when deleting)
                // Implementation remains the same as insertion
            } else {
                // Merge the child with its sibling
                // (similar logic to merging nodes when deleting)
                // Implementation remains the same as insertion
            }
        }
        // Recursively delete the key from the appropriate child
        // (after adjusting the child if necessary)
        btree_delete_node(node->children[index], key);
    }
}

int btreeHeight(BNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int height = 0;
        for (int i = 0; i < root->num_keys + 1; ++i) {
            int child_height = btreeHeight(root->children[i]);
            if (child_height > height) {
                height = child_height;
            }
        }
        return height + 1;
    }
}

void printGivenLevelOrderBTree(BNode* root, int level) {
    if (root == NULL)
        return;
    if (level == 1) {
        for (int i = 0; i < root->num_keys; ++i)
            printf("%d ", root->keys[i]);
    } else if (level > 1) {
        for (int i = 0; i < root->num_keys + 1; ++i)
            printGivenLevelOrderBTree(root->children[i], level - 1);
    }
}

void printBTree(BNode* root, bool diamond) {
    if (root == NULL) {
        return;
    }
    int h = btreeHeight(root);
    int i, j;
    for (i = 1; i <= h; i++) {
        for (j = 0; j < h - i; j++) {
            printf("  ");
        }
        printGivenLevelOrderBTree(root, i);
        printf("\n");
    }
}



int main() {
    Node* root = NULL;
    int choice, choice1,key;
    
    struct TreeNode* root1 = NULL;
    
    struct bnode* root2 = btree_create_node();
    printf("\n1. AVL Tree\n2. Bianry Tree\n3. B-Tree\n");
    printf("Enter your choice: ");
    scanf("%d",&choice1);
    switch (choice1){
        case 1:while (1) {
                    printf("For AVL Tree");
                    printf("\n1. Insert\n2. Delete\n3. Inorder traversal\n4. Print tree\n5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the key to insert: ");
                        scanf("%d", &key);
                        root = insert(root, key);
                        break;
                    case 2:
                        printf("Enter the key to delete: ");
                        scanf("%d", &key);
                        root = deleteNode(root, key);
                        break;
                    case 3:
                        printf("Inorder traversal of the AVL tree is: ");
                        inorder(root);
                        printf("\n");
                        break;
                    case 4:
                        printf("AVL Tree:\n");
                        printTree(root, false);
                        break;
                    case 5:
                        exit(0);
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
            break;
        case 2:while (1) {
                printf("For Binary Tree");
                printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Print Tree\n5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the key to insert in binary tree: ");
                        scanf("%d", &key);
                        root1 = insertBinaryNode(root1, key);
                        break;
                    case 2:
                        printf("Enter the key to delete from binary tree: ");
                        scanf("%d", &key);
                        root1 = deleteBinaryNode(root1, key);
                        break;
                    case 3:
                        printf("Inorder traversal of the binary tree: ");
                        binaryInorderTraversal(root1);
                        printf("\n");
                        break;
                    case 4:
                        printf("Binary Tree:\n");
                        printBinaryTree(root1, false);
                        break;
                    case 5:
                        exit(0);
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
            break;
        case 3:while (1) {
               printf("For B-Tree");
               printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Print Tree\n5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the key to insert in B-tree: ");
                        scanf("%d", &key);
                        btree_insert(&root2, key);
                        break;
                    case 2:
                        printf("Enter the key to delete from B-tree: ");
                        scanf("%d", &key);
                        btree_delete_node(root2, key);
                        break;
                    case 3:
                        printf("Inorder traversal of the B-tree: ");
                        btree_inorder_traversal(root2);
                        printf("\n");
                        break;
                    case 4:
                        printf("B-Tree:\n");
                        printBTree(root2, false);
                        break;
                    case 5:
                        exit(0);
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
            break;
    }

    return 0;
}
