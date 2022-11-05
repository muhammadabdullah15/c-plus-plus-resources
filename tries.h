#pragma once

#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 27;

class Trie
{
private:
    struct TrieNode
    {
        TrieNode *children[ALPHABET_SIZE];
        bool isEndOfWord;
    };

    TrieNode *root;

    TrieNode *getNewNode()
    {
        TrieNode *pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

public:
    Trie()
    {
        root = getNewNode();
    }

    void insert(string key)
    {
        TrieNode *temp = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!temp->children[index])
                temp->children[index] = getNewNode();

            temp = temp->children[index];
        }
        temp->isEndOfWord = true;
        return;
    }

    bool searchTrie(string key)
    {
        TrieNode *temp = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!temp->children[index])
                return false;

            temp = temp->children[index];
        }

        return (temp->isEndOfWord);
    }
};