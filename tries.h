#pragma once

#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 27;

/**
 * @brief Trie Class
 *
 */
class Trie
{
private:
    /**
     * @brief Structure for a single node of the trie
     *
     */
    struct TrieNode
    {
        TrieNode *children[ALPHABET_SIZE]; // Array of all the pointers to children
        bool isEndOfWord;                  // True if this node is the end of a word
    };

    TrieNode *root; // Pointer to the root of the trie

    /**
     * @brief Creates a new trie node
     *
     * @return A new node
     */
    TrieNode *getNewNode()
    {
        TrieNode *pNode = new TrieNode;
        pNode->isEndOfWord = false;

        // Initializing all children to NULL
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

public:
    /**
     * @brief Construct a new Trie object
     *
     */
    Trie()
    {
        root = getNewNode(); // Create a new node as root
    }

    /**
     * @brief Inserts a word into the trie
     *
     * @param key word to insert
     */
    void insert(string key)
    {
        TrieNode *temp = root;

        // Traverses the trie by using each character of the key to travel the specified branch
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            // If there is no character leading to the word, create a branch towards it
            if (!temp->children[index])
                temp->children[index] = getNewNode();

            temp = temp->children[index];
        }

        temp->isEndOfWord = true; // Marks the current position as the end of word
        return;
    }

    /**
     * @brief Searches the trie for passed key
     *
     * @param key Word to search
     * @return true if word is in trie
     * @return false if word is not in trie
     */
    bool searchTrie(string key)
    {
        if (key.find('-') != string::npos)
            return false;

        TrieNode *temp = root;
        // Traverses the trie by using each character of the key to travel the specified branch

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            // If there is no character leading to the word, return false
            if (!temp->children[index])
                return false;

            temp = temp->children[index];
        }

        return (temp->isEndOfWord); // If current position is the end of word,return true
    }
};