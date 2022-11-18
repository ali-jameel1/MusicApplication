
#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Album.h"


using namespace std;

class AlbumArray{
    public:
        //Constructors and deststructors
        AlbumArray();
        ~AlbumArray();
        AlbumArray(AlbumArray &);
        //Add, get and remove functions
        bool add(Album * a);
        bool get(const string& artist, const string& title, Album** a) const;
        bool get(int index, Album** a) const;
        bool remove(const string& artist, const string& title, Album** a);
        bool remove(int index, Album** a);
        //Other
        int size() const;
        bool isFull() const;
        //Print
        void print() const;
        void printShort() const;
    private:
        Album** albumArr;
        int arrSize;
};

#endif