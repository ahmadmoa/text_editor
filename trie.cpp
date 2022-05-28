#include "trie.h"   

Trie::Trie() {
    root = new TrieNode();
    load_dic();
}

Trie::~Trie() {
    delete root;
}

void Trie::insertWord(QString& word) {
    TrieNode* currNode = root;
    
    for (QChar c : word) {
        if (currNode->children[c.toLatin1() - 'a'] == NULL)
            currNode->children[c.toLatin1() - 'a'] = new TrieNode();
        currNode = currNode->children[c.toLatin1() - 'a'];
    }
    currNode->terminating = true;
}

void Trie::load_dic() {
    QFile file("words.txt");

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            insertWord(line);
        }
        file.close();
    }
}

bool Trie::searchWord(QString& word) {
    TrieNode* currNode = root;
    for (QChar c : word) {
        c.toLower();
        if (currNode->children[c.toLatin1() - 'a'] != NULL)
            currNode = currNode->children[c.toLatin1() - 'a'];
        else return false;
    }
    return currNode->terminating;
}
