
#ifndef SONGARRAY_H
#define SONGARRAY_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Song.h"


using namespace std;

class SongArray{
    public:
        //Constructors and destructors
        SongArray();
        ~SongArray();
        SongArray(SongArray &);
        //Add, get and remove functions
        bool add(Song *);
        bool add (int index, Song *);
        bool get(const string& artist, const string& title, Song**) const;
        bool get(int index, Song**) const;
        bool remove(const string& artist, const string& title, Song**);
        bool remove(int index, Song**);
        //Other
        int size() const;
        bool isFull() const;
        //Print
        void print() const;
    private:
        Song** songArr;
        int arrSize;
};

#endif