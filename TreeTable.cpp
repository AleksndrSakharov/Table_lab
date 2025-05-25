#include "TreeTable.h"

bool TreeTable::IsFull() const {
    try {
        PTreeNode node = new TreeNode;
    }
    catch(const char*) {
        return true;
    }
    return false;
}

PDataValue TreeTable::FindRecord(Key key){
    PTreeNode pNode = _pRoot;
    _ppRef = &pNode;
    _efficiency = 0;
    while (pNode != nullptr) {
        _efficiency++;
        if (pNode->_key == key){
            break;
        }
        if (pNode->_key < key){
            _ppRef = &pNode->right;
        }
        if (pNode->_key > key){
            _ppRef = &pNode->left;
        }
        pNode = *_ppRef;
    }
    return pNode ? nullptr: pNode->_data;
}

void TreeTable::InsRecord(Key key, PDataValue data){
    if (IsFull()){
        throw "No memory";
    }
    if (FindRecord(key) != nullptr) {
        throw "duplicate";
    }
    _dataCount++;
    *_ppRef = new TreeNode(key, data);
}

Key TreeTable::GetKey() const {
    if (_pCurrent == nullptr){
        return "";
    }
    return _pCurrent->_key;
}
PDataValue TreeTable::GetValue() const {
    if (_pCurrent == nullptr){
        return nullptr;
    }
    return _pCurrent->_data;
}

void TreeTable::DelRecotd(Key key){
    if (FindRecord(key) == nullptr){
        throw "No element";
    }
    PTreeNode pNode = *_ppRef;
    if (pNode->_right == nullptr){
        *_ppRef = pNode->_left;
    }
    else{
        if (pNode->_left == nullptr){
            _ppRef = pNode->_right;
        }
        else{
            PTreeNode pn = pNode->_left;
            PTreeNode* ppr = &(pNode->_left) ;
            while(pn->_right != nullptr){
                ppr = &(pn->_right);
                pn = *ppr;
            }
            pNode->_key = pn->_key;
            pNode->_data = pn->_data;
            pNode = pn;
            *ppr = pn->_left;
        }

    }
    delete(pNode);
}