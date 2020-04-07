// https://www.youtube.com/watch?v=co4_ahEDCho
// https://www.techiedelight.com/huffman-coding/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class HuffmanEncoding{
public:
	HuffmanEncoding(unordered_map<char, int> charMap){
		for(auto it = charMap.begin(); it != charMap.end(); it++){
			TreeNode *newNode = createNode(it->first, it->second);
			_pq.push(newNode);
		}
	}
	// Build the Huffman tree
	void buildTree(){
		while(_pq.size() > 1){
			TreeNode *left = _pq.top(); _pq.pop();
			TreeNode *right = _pq.top(); _pq.pop();
			TreeNode *combinedNode = createNode('#', left->frequency+right->frequency);

			combinedNode->left = left;
			combinedNode->right = right;
			// Insert into the priority queue
			_pq.push(combinedNode);
		}
		// The last node is the root node
		_root = _pq.top(); _pq.pop();
	}
	// Build the Huffman codes from the Huffman tree
	void buildHuffmanCodes(){
		TreeNode *temp = _root;
		buildHuffmanCodesHelper(temp, "");
		for(auto it : _huffmanCodes){
			cout << it.first << ": " << it.second << endl;
		}
	}
	// Encode a string
	string encode(string str){
		string encodedString = "";
		for(int i = 0; i < str.size(); i++){
			encodedString += _huffmanCodes[str[i]];
		}
		return encodedString;
	}
	// Decode a string
	string decode(string encodedString){
		string decodedString = "";
		int index = -1;
		while(index < (int)encodedString.size()){
			TreeNode *temp = _root;
			decodeHelper(temp, encodedString, decodedString, index);
		}
		return decodedString;
	}
	// Print pre-order traversal of the tree
	void printTree(){
		TreeNode *temp = _root;
		printTreeHelper(temp);
	}
private:
	// Node structure
	struct TreeNode
	{
		TreeNode *left, *right;
		char data;
		int frequency;
		TreeNode(char newData, int newFrequency){
			data = newData;
			frequency = newFrequency;
			left = NULL, right = NULL;
		}
	};
	// Create a new node of the tree
	TreeNode *createNode(char data, int frequency){
		TreeNode *newNode = new TreeNode(data, frequency);
		return newNode;
	}
	// For min-heap priority queue
	struct SortPriorityQueue{
		bool operator()(TreeNode *node1, TreeNode *node2){
			return node1->frequency > node2->frequency;
		}
	};
	// Print the pre-order traversal of the tree
	void printTreeHelper(TreeNode *root){
		if(!root)
			return;
		cout << root->data << " ";
		printTreeHelper(root->left);
		printTreeHelper(root->right);
	}
	// Build Huffman codes
	void buildHuffmanCodesHelper(TreeNode *root, string code){
		if(!root)
			return;
		// If leaf found
		if(!root->left && !root->right){
			_huffmanCodes[root->data] = code;
			return;
		}
		// Go left
		buildHuffmanCodesHelper(root->left, code+'0');
		// Go right
		buildHuffmanCodesHelper(root->right, code+'1');
	}
	// Decode a string
	void decodeHelper(TreeNode *root, string &encodedString, string &decodedString, int &index){
		if(!root)
			return;
		// If hit a leaf node
		if(!root->left && !root->right){
			decodedString += root->data;
			return;
		}
		index++; // Doing this because C++ was complaining about non-const lvalue reference something
		if(encodedString[index] == '0')
			decodeHelper(root->left, encodedString, decodedString, index);
		else if(encodedString[index] == '1')
			decodeHelper(root->right, encodedString, decodedString, index);
	}
	// Root node
	TreeNode *_root;
	// Priority queue
	priority_queue<TreeNode *, vector<TreeNode *>, SortPriorityQueue> _pq;
	// Store the huffman codes for each characters
	unordered_map<char, string> _huffmanCodes;
};

int main(){
	string str = "Huffman coding is a data compression algorithm.";
	unordered_map<char, int> charMap;
	for(auto ch : str)
		charMap[ch]++;
    HuffmanEncoding obj1(charMap);
    cout << "Building the tree\n";
    obj1.buildTree();
    cout << "\nTree built\n";
    cout << "\nnPrinting the Huffman codes\n";
    obj1.buildHuffmanCodes();
    string encodedString = obj1.encode(str);
    cout << "\nEncoded string is: " << encodedString << endl;
    string decodedString = obj1.decode(encodedString);
    cout << "\nDecoded string is: " << decodedString << endl;
    
    return 0;
}
