#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for the Huffman Tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

// Recursive function to generate Huffman Codes
void generateCodes(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;

    // Leaf node, store the code
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build Huffman Tree and encode the input
void buildHuffmanTree(const string &text)
{
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }

    // Priority queue to store nodes of the Huffman Tree
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Create a leaf node for each character
    for (auto &pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with combined frequency
        Node *sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    // Root of the Huffman Tree
    Node *root = pq.top();

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Display the Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto &pair : huffmanCode)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Calculate original and compressed size
    int originalSize = text.length() * 8; // 8 bits per character (ASCII)
    int compressedSize = 0;

    // Calculate the size of the compressed data
    for (char ch : text)
    {
        compressedSize += huffmanCode[ch].length();
    }

    // Calculate and display compression ratio
    double compressionRatio = (double)originalSize / compressedSize;
    cout << "\nOriginal Size (bits): " << originalSize << endl;
    cout << "Compressed Size (bits): " << compressedSize << endl;
    cout << "Compression Ratio: " << compressionRatio << endl;
}

int main()
{
    string text;
    cout << "Enter a paragraph: ";
    getline(cin, text);

    // Build the Huffman Tree and generate codes
    buildHuffmanTree(text);

    return 0;
}
