#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* initialization() {
    return NULL;
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return findHeight(node->left) - findHeight(node->right);
}

void updateHeight(struct Node* node) {
    if (node == NULL) {
        return;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    node->height = max(leftHeight, rightHeight) + 1;
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

struct Node* insert(struct Node* node, int value, int* rotationCounter) {
    if (node == NULL) {
        return createNode(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value, rotationCounter);
    } else if (value > node->value) {
        node->right = insert(node->right, value, rotationCounter);
    } else {
        return node;
    }

    updateHeight(node);

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->value) {
        (*rotationCounter)++;
        return rotateRight(node);
    }

    if (balanceFactor < -1 && value > node->right->value) {
        (*rotationCounter)++;
        return rotateLeft(node);
    }

    if (balanceFactor > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        (*rotationCounter)++;
        return rotateRight(node);
    }

    if (balanceFactor < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        (*rotationCounter)++;
        return rotateLeft(node);
    }

    return node;
}

struct Node* search(struct Node* node, int value) {
    if (node == NULL) {
        return NULL;
    } else if (value < node->value) {
        return search(node->left, value);
    } else if (value > node->value) {
        return search(node->right, value);
    } else {
        return node;
    }
}

int calculateMaxHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return max(calculateMaxHeight(node->left), calculateMaxHeight(node->right)) + 1;
}

enum Color {
    RED,
    BLACK
};

struct RBNode {
    int value;
    enum Color color;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
};

struct RBNode* RBInitialization() {
    return NULL;
}

struct RBNode* RBCreateNode(int value) {
    struct RBNode* newNode = (struct RBNode*)malloc(sizeof(struct RBNode));
    newNode->value = value;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void RBLeftRotate(struct RBNode** root, struct RBNode* node) {
    struct RBNode* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != NULL) {
        node->right->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == NULL) {
        *root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RBRightRotate(struct RBNode** root, struct RBNode* node) {
    struct RBNode* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != NULL) {
        node->left->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == NULL) {
        *root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RBFixViolation(struct RBNode** root, struct RBNode* node) {
    struct RBNode* parent = NULL;
    struct RBNode* grandparent = NULL;

    while (node != *root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            struct RBNode* uncle = grandparent->right;

            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    RBLeftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                RBRightRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        } else {
            struct RBNode* uncle = grandparent->left;

            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    RBRightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                RBLeftRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        }
    }

    (*root)->color = BLACK;
}

struct RBNode* RBInsert(struct RBNode* root, int value) {
    struct RBNode* newNode = RBCreateNode(value);
    struct RBNode* current = root;
    struct RBNode* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (value < current->value) {
            current = current->left;
        } else if (value > current->value) {
            current = current->right;
        } else {
            return root;
        }
    }

    newNode->parent = parent;

    if (parent == NULL) {
        root = newNode;
    } else if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    RBFixViolation(&root, newNode);

    return root;
}

struct RBNode* RBSearch(struct RBNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return RBSearch(root->left, value);
    } else {
        return RBSearch(root->right, value);
    }
}

int main() {
    struct Node* tree1 = NULL;
    struct Node* raiz = NULL;
    int valor = 0, a = 0;
    int contadorAVL = 0; // Rotation counter for AVL tree
    int contadorAVP = 0; // Counter for AVP tree
    int contadorCor = 0; // Counter for color violations

    tree1 = initialization();

    while (1) {
        scanf("%d", &valor);
        if (valor == 8) {
            a = 1;
        }
        if (valor == -1) {
            break;
        }

        tree1 = insert(tree1, valor, &contadorAVL);
        struct Node* novoNoh = createNode(valor);
        raiz = insertNode(raiz, novoNoh);
        markViolation(&raiz, novoNoh, &contadorAVP, &contadorCor);
    }

    int altNohPreto = maxBlackHeight(raiz);
    int esquerdasubArvoreAltura = subtreeHeight(raiz->left);
    int direitasubArvoreAltura = subtreeHeight(raiz->right);

    // Print AVL tree results
    printf("%d, ", calculateMaxHeight(tree1) - 1);
    printf("%d, ", findHeight(tree1->left));
    printf("%d\n", findHeight(tree1->right));

    int altArvore = maxHeight(raiz);

    // Print AVP tree results
    printf("%d, %d, %d\n", altArvore - 1, esquerdasubArvoreAltura, direitasubArvoreAltura);
    printf("%d\n", altNohPreto);
    printf("%d, ", contadorCor);
    printf("%d, ", contadorAVP);
    printf("%d\n", contadorAVL);

    deallocateTree(raiz);

    return 0;
}

