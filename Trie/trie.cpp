#include<iostream>

using namespace std;

class TrieNode {
    public:
    char data;   // current character
    TrieNode* children[26];   // 26 alphabets

    bool isTerminal;  // to check if the word ends here

    TrieNode(char ch){    // Initialize the node with the character
        data = ch;
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};


// Class for trie
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');   // Root Node
    }

    void insertCharacter(TrieNode* root, string word){
        if(word.length() == 0){                 //If we have reached the last character mark it terminal
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';             // Find the index of current character

        if(root ->children[index] != nullptr){
            insertCharacter(root->children[index], word.substr(1));          // If the current index is already filled
        }
        else{
            TrieNode* child = new TrieNode(word[0]);       // Create a new node and insert at the required index
            root->children[index] = child;
            insertCharacter(child, word.substr(1));
        }
    }

    void insertWord(string word){
        insertCharacter(root, word);
    }

    bool searchWord(string word){
        return searchCharacter(root, word);
    }

    bool searchCharacter(TrieNode* root, string word){
        if(word.length() == 0){                    // If the word ends then we will check if the character is terminal, if the current character is terminal then we will return true, else false
            return root->isTerminal;
        }

        int index = word[0] - 'A';                   // Find the correct index

        if(root->children[index] != nullptr){
            return searchCharacter(root->children[index], word.substr(1));    // If the character is present at index, go to the next character.
        }
        else{
            return false;                   // If any middle character is null then return false
        }

        return false;
    }

    void deleteWord(string word){
        deleteCharacter(root, word);
    }


    /* There are three cases for deletion
        1. If the character is the last character of the word, then we will mark the isTerminal as false
        and then return
        2. if the character is not the last character, and if it is not the predecessor of any character in any other word, we can simply delete that and delete its predecessors also
        3. if the character is not the last character, and if the predecessor of any character in any other word, then we cannot delete that character, we will just move back.
    */

    void deleteCharacter(TrieNode* root, string word){
        if(word.length() == 0){     // If the word is ended then mark isTerminal as false
            root->isTerminal = false; 
            return;
        }

        bool flag = true;
        int index = word[0] - 'A';
        deleteCharacter(root->children[index], word.substr(1));       // Call recursively
            for(int i = 0; i < 26; i++){
                if(root->children[index]->children[i] != nullptr){      // Check if all the children of the next character are null
                    flag = false;
                }
            }

        if(flag){    // If all the child characters of the next node are null delete the next node 
            root->children[index] = nullptr;
        }
    } 
};

int main(){
    Trie T;
    T.insertWord("HELLO");
    T.insertWord("HELLI");
    T.insertWord("HELLY");
    T.insertWord("HELLYP");
    cout<<"Present "<<T.searchWord("HELLYP")<<endl;
    T.deleteWord("HELLYP");
    cout<<"Present "<<T.searchWord("HELLYP")<<endl;
    cout<<"Present "<<T.searchWord("HELLO")<<endl;
}