"# Avl_tree_implementation" 
# AVL Tree Implementation in C++

A complete implementation of a self-balancing AVL (Adelson-Velsky and Landis) tree data structure in C++. This project demonstrates automatic tree balancing through rotations to maintain optimal search performance.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Algorithm Details](#algorithm-details)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Example Output](#example-output)
- [Complexity Analysis](#complexity-analysis)
- [Contributing](#contributing)
- [License](#license)

## Overview

An AVL tree is a self-balancing binary search tree where the heights of the two child subtrees of any node differ by at most one. When this property is violated after an insertion or deletion, the tree performs rotations to restore balance, ensuring O(log n) time complexity for search, insertion, and deletion operations.

## Features

- **Automatic Balancing**: Tree automatically rebalances after insertions
- **Height Tracking**: Each node maintains its height for efficient balance factor calculation
- **Rotation Operations**: Implements both left and right rotations
- **Four Balance Cases**: Handles Left-Left, Right-Right, Left-Right, and Right-Left imbalances
- **BST Property**: Maintains binary search tree ordering
- **Duplicate Handling**: Prevents insertion of duplicate values

## Algorithm Details

### Balance Factor

Balance Factor = Height(Left Subtree) - Height(Right Subtree)

text

A node is considered balanced if its balance factor is -1, 0, or 1.

### Rotation Cases

1. **Left-Left (LL)**: Right rotation when left subtree is taller and insertion occurs in left child's left subtree
2. **Right-Right (RR)**: Left rotation when right subtree is taller and insertion occurs in right child's right subtree
3. **Left-Right (LR)**: Left rotation on left child, then right rotation on root
4. **Right-Left (RL)**: Right rotation on right child, then left rotation on root

## Usage

### Compilation

g++ -o avl_tree avl_tree.cpp

text

### Execution

./avl_tree

text

### Basic Example

node *root = nullptr;

// Insert values
root = insertAVL(root, 10);
root = insertAVL(root, 20);
root = insertAVL(root, 30);
root = insertAVL(root, 15);

// Display tree (preorder traversal)
preorder(root);

text

## Code Structure

### Node Structure
struct node {
int height; // Height of the node
int data; // Value stored in the node
node* left; // Pointer to left child
node* right; // Pointer to right child
};

text

### Core Functions

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `insertAVL()` | Inserts a new node and rebalances the tree | O(log n) |
| `leftrotate()` | Performs left rotation | O(1) |
| `rightrotate()` | Performs right rotation | O(1) |
| `Balancefact()` | Calculates balance factor of a node | O(1) |
| `updateHeight()` | Updates height of a node | O(1) |
| `height()` | Returns height of a node | O(1) |
| `preorder()` | Preorder traversal of the tree | O(n) |

## Example Output

For the input array `{5, 2, 2, 4, 5, 5}`:

Preorder
5 2 4

text

**Note**: Duplicate values (2, 5) are automatically rejected to maintain BST properties.

## Complexity Analysis

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Search | O(log n) | O(log n) |
| Insertion | O(log n) | O(log n) |
| Deletion | O(log n) | O(log n) |
| Space | O(n) | O(n) |

The balanced nature of AVL trees guarantees logarithmic height, unlike regular BSTs which can degrade to O(n) in worst case.

## How It Works

1. **Insertion**: New nodes are inserted following BST rules
2. **Height Update**: Heights are updated along the insertion path
3. **Balance Check**: Balance factor is calculated for each ancestor node
4. **Rotation**: Appropriate rotations are performed if balance factor exceeds ±1
5. **Propagation**: Balancing propagates up the tree to the root

## Limitations

- Currently only supports integer values
- Duplicate values are not allowed
- Deletion operation is not implemented
- Only preorder traversal is provided

## Future Enhancements

- [ ] Implement deletion operation with rebalancing
- [ ] Add inorder and postorder traversal methods
- [ ] Template support for generic data types
- [ ] Add search functionality
- [ ] Implement tree visualization
- [ ] Add unit tests

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available under the [MIT License](LICENSE).

## Author

[Muhammad Mutaal Khan]

## Acknowledgments

- Based on the AVL tree data structure invented by Georgy Adelson-Velsky and Evgenii Landis in 1962
- Part of Data Structures and Algorithms coursework

---

**Note**: This implementation is designed for educational purposes and demonstrates the fundamental concepts of self-balancing binary search trees.

The balance factor of a node is calculated as:


