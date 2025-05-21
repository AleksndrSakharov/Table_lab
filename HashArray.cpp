#include"HashArray.h"

HashArray::HashArray(size_t size, size_t hashStep){
    _tableSize = size;
    _hashStep = hashStep;
    _records =new PTabRecord[_tableSize];
    for(size_t i = 0; i < _tableSize; i ++){
        _records[i] = nullptr;
    }
    //_mark = new PTabRecord();

}

HashArray::~HashArray(){
    for(size_t i = 0; i < _tableSize; i++){
        delete _records[i];
    }
    delete [] _records;
    delete [] _mark;
}

bool HashArray::IsFull() const{
    return _dataCount >= _tableSize;
}
bool HashArray::Reset(){
    _curPos = 0;
    return IsTabEnded();
}
bool HashArray::IsTabEnded() const{
    return _curPos >= _dataCount;
}
bool GoNext(){
    // if(!IsTabEnded()){
    //     _curPos++;
    // }
    // return IsTabEnded();
}
Key HashArray::GetKey() const{

}
PDataValue HashArray::GetValue() const{

}

PDataValue HashArray::FindRecord(Key key){

}
void HashArray::DelRecotd(Key key){

}
void HashArray::InsRecord(Key key, PDataValue value){

}