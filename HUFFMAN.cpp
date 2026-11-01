#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node of Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare frequencies for Min Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

unordered_map<char, string> codes;

// Generate Huffman Codes
void generateCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        codes[root->ch] = code.empty() ? "0" : code;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

// Build Huffman Tree
Node* buildTree(string text) {

    unordered_map<char, int> freq;

    // Count frequency of characters
    for (char c : text)
        freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert characters into Min Heap
    for (auto x : freq)
        pq.push(new Node(x.first, x.second));

    // Combine two minimum frequency nodes
    if (pq.size() == 1) {
        Node* temp = pq.top();
        pq.pop();

        Node* root = new Node('\0', temp->freq);
        root->left = temp;
        return root;
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

// Encode Text
string encode(string text) {
    string result = "";

    for (char c : text)
        result += codes[c];

    return result;
}

// Decode Text
string decode(string encoded, Node* root) {
    string result = "";
    Node* temp = root;

    for (char bit : encoded) {

        if (bit == '0')
            temp = temp->left;
        else
            temp = temp->right;

        if (temp->left == NULL && temp->right == NULL) {
            result += temp->ch;
            temp = root;
        }
    }

    return result;
}

// Main Function
int main() {

    string text;

    cout << "Enter text: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Text cannot be empty.";
        return 0;
    }

    Node* root = buildTree(text);

    generateCodes(root, "");

    cout << "\nHuffman Codes:\n";

    for (auto x : codes)
        cout << x.first << " : " << x.second << endl;

    string encoded = encode(text);

    cout << "\nOriginal Text: " << text;
    cout << "\nEncoded Text: " << encoded;

    string decoded = decode(encoded, root);

    cout << "\nDecoded Text: " << decoded;

    return 0;
}






































// 1. What is Huffman Encoding?
// Huffman Encoding is a lossless data compression technique that reduces the number of bits required to represent data.
// - Lossless: The original text can be recovered exactly.
// - Variable-length coding: Frequent characters generally get shorter codes, while less frequent characters get longer codes.
// - Greedy algorithm: It repeatedly combines the two nodes with the lowest frequencies.
// - Prefix-free coding: No character's code is the prefix of another character's code.


// 2. What is the greedy strategy?
// A greedy algorithm makes the best available local choice at every step.

// In Huffman Encoding, the greedy choice is:

// Always select the two nodes with the smallest frequencies and merge them.

// 3. Huffman tree: important terminology

// Node

// A single element of the tree. It stores a frequency and may store a character.

// Leaf node

// A node that has no children. It represents an original character.

// Internal node

// A parent node created by adding the frequencies of two nodes.

// Root node

// The topmost node. Its frequency equals the total number of characters in the input


// 4. Complete algorithm
// Write this algorithm in your practical journal or exam.

// Algorithm: Huffman Encoding
// 1. Start.
// 2. Read the input text.
// 3. Count the frequency of each character.
// 4. Create one leaf node for every distinct character.
// 5. Insert all nodes into a min-priority queue.
// 6. While the queue contains more than one node:
//    - Remove the two nodes with the smallest frequencies.
//    - Create a parent node with frequency equal to their sum.
//    - Make the removed nodes its left and right children.
//    - Insert the parent node back into the queue.
// 7. The remaining node becomes the root of the Huffman tree.
// 8. Traverse the tree, assigning 0 to left edges and 1 to right edges.
// 9. Encode the input by replacing each character with its code.
// 10. Decode the bit string by traversing the tree.
// 11. Display the codes, encoded text, and decoded text.
// 12. Stop.