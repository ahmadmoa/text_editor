#pragma once
#include <qstring.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>

struct TrieNode {
    bool terminating = false;
    TrieNode* children[26] = { NULL };
};

class Trie {
    TrieNode* root;
public:
    Trie();
    ~Trie();

    void insertWord(QString&);
    void load_dic();
    bool searchWord(QString&);

};
