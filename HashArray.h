#include"HashTable.h"
#include"ArrayTable.h"

class HashArray: public HashTable{
    protected:
        size_t _tableSize;
        size_t _hashStep;
        PTabRecord* _records;
        size_t _curPos;
        size_t _freePos;
        PTabRecord _mark;
        size_t GetNextPos(size_t pos){
            return (pos + _hashStep) % _tableSize;
        }
    public:
        HashArray(size_t size = 100, size_t hashStep = 7);  // посмотреть правильный рассчёт hashStep
        ~HashArray();
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