#include "SortTable.h"
#include "ArrayTable.h"

void SortTable::InsertSort(PTabRecord *data, size_t count){
    PTabRecord tmp;
    _efficiency = 0;
    for(int i = 0, j; i < _dataCount; i++){
        tmp =_records[i];
        for(j = i - 1; j > -1; j--){
            if(_records[j]->_key > tmp ->_key){
                _records[j+1] = _records[j];
                _efficiency++;
            }else{
                break;
            }
        }
        _records[j+1] = tmp;
    }
}

void SortTable::MergeSort(PTabRecord *data, size_t count){
    PTabRecord* pdata = data;
    PTabRecord* pbuf = new PTabRecord[count];
    PTabRecord* tmp = pbuf;
    if(pdata == tmp){
        for( int i = 0; i < count; i++){
            pbuf[i] = pdata[i];
        }
    }
    delete [] tmp;
}
void SortTable::MergeSorter(PTabRecord* &data, PTabRecord* &buffer, size_t size){
    size_t n1 = (size + 1)/2;
    size_t n2 = size - n1;
    if(size > 2){
        PTabRecord* pdata2 = data + n1;
        PTabRecord* pbuf2 = buffer + n1;
        MergeSorter(data, buffer, n1);
        MergeSorter(pdata2, pbuf2, n2);  
    }
    MergeData(data, buffer, n1, n2);
}
void SortTable::MergeData(PTabRecord* &data, PTabRecord* &buffer, size_t n1, size_t n2){
    size_t i = 0, i1 = 0, i2 = 0;
    PTabRecord* pdata1 = data;
    PTabRecord* pdata2 = data + n1;
    while(i1 < n1 && i2 < n2){
        if(pdata1[i1]->GetKey() < pdata2[i2]->GetKey()){
            buffer[i++] = pdata1[i1++]; 
        }
        else{
            buffer[i++] = pdata2[i2++]; 
        }
    }
    while (i1 < n1)
    {
       buffer[i++] = pdata1[i1++];
    }
    while (i2 < n2)
    {
       buffer[i++] = pdata2[i2++];
    }
    _efficiency += int(n1) + int(n2);
    data = buffer;
    buffer = pdata1;
}

void SortTable::QuickSort(PTabRecord *data, size_t count){
    size_t pivot;
    size_t n1, n2;
    if(count > 1){
        QuickSplit(data, count, pivot);
        n1 = pivot + 1;
        n2 = count - n1;
        QuickSort(data, n1 - 1);
        QuickSort(data + n1, n2);
    }
}
void SortTable::QuickSplit(PTabRecord *data, size_t count, size_t& pivot){
    PTabRecord ppivot = data[0];
    PTabRecord tmp;
    size_t i1 = 1, i2 = count - 1;
    while(i1 <= i2){
        while (i1 < count && !(data[i1]->GetKey() > ppivot->GetKey()))
        {
            i1++;
        }
        while (data[i2]->GetKey() > ppivot->GetKey())
        {
            i2--;
        }
        if(i1 < i2){
            tmp = data[i1];
            data[i1] = data[i2];
            data[i2] = tmp;
        }
    }
    _efficiency += int(count);
    pivot = i2;
    data[0] = data[i2];
    data[i2] = ppivot;
}

void SortTable::SortData(){
    _efficiency = 0;
    switch (_sortMethod)
    {
        case SortMethod::Insert:
            InsertSort(_records, _dataCount);
            break;
        case SortMethod::Merge:
            MergeSort(_records, _dataCount);
            break;
        case SortMethod::Quick:
            QuickSort(_records, _dataCount);
            break;
        default:
            throw "Unavailable sort method";
    }
}
    
SortTable& SortTable::operator=(const ScanTable& st){
    if (_records != nullptr){
        for (size_t i = 0; i < _dataCount; i++){
            delete _records[i];
        }
        delete [] _records;
    }

    _tabSize = st._tabSize;
    _dataCount = st.GetDataCount();
    _records = new PTabRecord[_tabSize];
    for(size_t i = 0; i < _dataCount; i++){
        _records[i] = (PTabRecord)st._records[i]->GetCopy();
    }

    SortData();
    _curPos = 0;
    return *this;
}

PDataValue SortTable::FindRecord(Key key){
    size_t i, i1 = 0, i2 = _dataCount - 1;
    _efficiency = 0;
    while(i1 <= i2){
        _efficiency ++;
        i = (i1 + i2)/ 2;
        if(_records[i]->GetKey() == key){
            i1 = i1 + 1;
            i2 = i;
        }
        if(_records[i]->GetKey() > key){
            i2 = i - 1;
        }
        else
        {
            i1 = i + 1;
        }
    }
    if(i2 < 0 || _records[i]->GetKey() < key){
        i2++;
    }
    _curPos = i2;
    if(i2 < _dataCount && _records[i2]->GetKey() == key){
        return _records[i2]->GetData();
    }
    return nullptr;
}
    void SortTable::DelRecotd(Key key){
        if (IsEmpty()) {
            throw "Table is empty";
        }
        
        PDataValue tmp = FindRecord(key);
        if (tmp == nullptr) {
            throw "Key not found";
        }
        
        delete _records[_curPos];
        for (size_t i = _curPos; i < _dataCount - 1; i++) {
            _records[i] = _records[i + 1]; 
        }
        _records[_dataCount - 1] = nullptr; 
        _dataCount--;
        Reset(); 
    }
    
    void SortTable::InsRecord(Key key, PDataValue data){
        if(IsFull()){
            throw "Table is full";
        }
        PDataValue tmp = FindRecord(key);
        if(tmp != nullptr){
            throw "Double insert";
        }
        for(size_t i = _dataCount; i > _curPos; i--){
            _records[i] = _records[i - 1];
        }
        _records[_curPos] = new TabRecord(key, data);
        _dataCount++;
        _curPos = 0;
    }