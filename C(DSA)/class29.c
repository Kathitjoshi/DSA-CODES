//trie tree  implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

// Function to create a new Trie node
struct TrieNode *createNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the Trie
void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = 1;
}

// Function to search for a word in the Trie
int search(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
        word++;
    }
    return current != NULL && current->isEndOfWord;
}

// Function to check if a Trie node has any children
int hasChildren(struct TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to delete a word from the Trie
int delete(struct TrieNode *root, const char *word, int depth) {
    if (!root) {
        return 0;
    }

    if (depth == strlen(word)) {
        if (root->isEndOfWord) {
            root->isEndOfWord = 0;
        }

        if (!hasChildren(root)) {
            free(root);
            return 1;
        }

        return 0;
    }

    int index = word[depth] - 'a';
    if (delete(root->children[index], word, depth + 1)) {
        free(root->children[index]);
        root->children[index] = NULL;

        return !root->isEndOfWord && !hasChildren(root);
    }

    return 0;
}


// Function to display words in the Trie in alphabetical order
void display(struct TrieNode *root, char *prefix, int length) {
    if (root->isEndOfWord) {
        prefix[length] = '\0';
        printf("%s\n", prefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            prefix[length] = 'a' + i;
            display(root->children[i], prefix, length + 1);
        }
    }
}

int main() {
    struct TrieNode *root = createNode();

    insert(root, "hello");
    insert(root, "world");
    insert(root, "hi");
    insert(root, "her");
    insert(root, "hero");

    printf("Search for 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search for 'world': %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("Search for 'helloworld': %s\n", search(root, "helloworld") ? "Found" : "Not Found");

    delete(root, "hello", 0);
    printf("Search for 'hello' after deletion: %s\n", search(root, "hello") ? "Found" : "Not Found");

    char prefix[100];
    printf("Words in Trie in alphabetical order:\n");
    display(root, prefix, 0);

    return 0;
}