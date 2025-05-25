#include "Table.h"

using PTreeNode = TreeNode*;

struct TreeNode
{
    Key _key;
    PDataValue _data;
    TreeNode() : _key(""), _data(nullptr){

    }
    TreeNode(Key key, PDataValue data) : _key(key), _data(data){

    }
};


class TreeTable : public Table
{
public:
     protected:
        size_t _tabSize;
        size_t _curPos;
        PTreeNode _pRoot;
        PTreeNode _ppRef;
        PTreeNode _pCurrent;
    public:
        TreeTable(size_t size = 100);  
        ~TreeTable();
        bool IsFull() const override;
        virtual bool Reset() override;
        virtual bool IsTabEnded() const override;
        virtual bool GoNext() override;

        virtual Key GetKey() const override;
        virtual PDataValue GetValue() const override;

        virtual PDataValue FindRecord(Key key) override;
        virtual void DelRecotd(Key key) override;
        virtual void InsRecord(Key key, PDataValue value) override;
};


