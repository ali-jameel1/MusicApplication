
#include "SongArray.h"

SongArray::SongArray(){
    songArr = new Song*[MAX_ARRAY];
    arrSize = 0;
}

SongArray::SongArray(SongArray& s): arrSize(s.arrSize){
    cout<<"SongArray Copy Made"<<endl;
    songArr = new Song*[MAX_ARRAY];
    for (int i = 0; i<s.arrSize; i++){
        songArr[i] = (new Song(*s.songArr[i]));
    }
    
}

SongArray::~SongArray(){
    for (int i = 0; i<arrSize; i++){
        delete songArr[i];
    }
    delete [] songArr;
}

bool SongArray::add(Song* s){
    if (!(arrSize <MAX_ARRAY)){
        return false;
    }
    songArr[arrSize] = s;
    arrSize++;
    return true;
}

bool SongArray::add(int index, Song* s){
    //Ensure space 
    if (!(arrSize <MAX_ARRAY)){
        return false;
    }
    //Ensure valid index
    if (index > arrSize || index < 0){
        return false;
    }
    //Shift cells
    for (int i = arrSize; i>index; i--){
        songArr[i] = songArr[i-1];
    }
    //Add new song
    songArr[index] = s;
    arrSize++;
    return true;
}

bool SongArray::get(const string& art, const string& tit, Song** s) const{
    for (int i = 0; i<arrSize; i++){
        if (songArr[i]->matches(art, tit)) {
            *s = songArr[i];
            return true;
        }
    }
    return false;
}

bool SongArray::get(int index, Song** s) const{
    if (index > arrSize-1 || index < 0){
        return false;
    }
    *s = songArr[index];
    return true;
}

bool SongArray::remove(const string& art, const string& tit, Song** s){
    //Iterate until we find where to remove
    int counter = -1;
    for (int i = 0; i<arrSize; i++){
        if (songArr[i]->matches(art, tit)) {
            *s = songArr[i];
            counter = i;
            break;
        }
    }
    //Shift values
    if (counter != -1){
        for (int i = counter; i<arrSize; i++){
            songArr[i] = songArr[i+1];
        }
        arrSize--;                   
        return true;
    }
    return false;
}

bool SongArray::remove(int index, Song** s){
    //Ensure index is valid
    if (index > arrSize-1 || index < 0){
        return false;
    }
    //Assign value at index
    *s = songArr[index];
    //Shift other values over
    for (int i = index; i<arrSize; i++){
        songArr[i] = songArr[i+1];
    }

    arrSize--;
    return true;
}

int SongArray::size() const{
    return arrSize;
}

bool SongArray::isFull() const{
    return arrSize == MAX_ARRAY;
}

void SongArray::print() const{
    for (int i = 0; i<arrSize; i++){
        songArr[i]->print();
    }
}