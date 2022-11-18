
#include "AlbumArray.h"

AlbumArray::AlbumArray(){
    albumArr = new Album*[MAX_ARRAY];
    arrSize = 0;
}

AlbumArray::AlbumArray(AlbumArray& a): arrSize(a.arrSize){
    albumArr = new Album*[MAX_ARRAY];
    for (int i = 0; i<a.arrSize; i++){
        albumArr[i] = (new Album(*a.albumArr[i]));
    }
    
}

AlbumArray::~AlbumArray(){
    // for (int i = 0; i<arrSize; i++){
    //     delete albumArr[i];
    // }
    delete [] albumArr;
}

bool AlbumArray::add(Album* a){
    //Ensure there is space
    if (!(arrSize <MAX_ARRAY)){
        return false;
    }
    //Iterate until wefind where to insert
    for (int i = arrSize; i>0; --i){
        if ((*a).lessThan(*albumArr[i-1])){
            albumArr[i] = albumArr[i-1];
        }else{
            albumArr[i] = a;
            ++arrSize;
            return true;
        }
    }
    albumArr[0] = a;
    ++arrSize;
    return true;
}

bool AlbumArray::get(const string& art, const string& tit, Album** a) const{
    //Iterate until we find an album that matches
    for (int i = 0; i<arrSize; i++){
        if (albumArr[i]->matches(art, tit)) {
            *a = albumArr[i];
            return true;
        }
    }
    return false;
}

bool AlbumArray::get(int index, Album** a) const{
    if (index > arrSize-1 || index < 0){
        return false;
    }
    *a = albumArr[index];
    return true;
}

bool AlbumArray::remove(const string& art, const string& tit, Album** a){
    int counter = -1;
    //Iterate until we find an album that matches
    for (int i = 0; i<arrSize; i++){
        if (albumArr[i]->matches(art, tit)) {
            *a = albumArr[i];
            counter = i;
            break;
        }
    }

    //If we found, shift other values over
    if (counter != -1){
        for (int i = counter; i<arrSize; i++){
            albumArr[i] = albumArr[i+1];
        }
        arrSize--;                   
        return true;
    }
    return false;
}

bool AlbumArray::remove(int index, Album** a){
    //Ensure valid index
    if (index > arrSize-1 || index < 0){
        return false;
    }

    //Assign value at index
    *a = albumArr[index];

    //Shift other values
    for (int i = index; i<arrSize; i++){
        albumArr[i] = albumArr[i+1];
    }

    arrSize--;
    return true;
}

int AlbumArray::size() const{
    return arrSize;
}

bool AlbumArray::isFull() const{
    return arrSize == MAX_ARRAY;
}

void AlbumArray::print() const{
    cout<<"AlbumArray"<<endl;
    for (int i = 0; i<arrSize; i++){
        albumArr[i]->print();
    }
}


void AlbumArray::printShort() const{
    for (int i = 0; i<arrSize; i++){
        albumArr[i]->printShort();
    }
}