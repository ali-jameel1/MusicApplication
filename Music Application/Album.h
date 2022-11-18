
#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>

#include "SongArray.h"

using namespace std;

class Album{
    public:
        //Constructors and destructors
        Album(const string& artist, const string& title);
        Album(Album&);
        ~Album();
        //Getters
        string getArtist() const;
        string getTitle() const;
        //Comparative functions
        bool matches(const string& artist, const string& title) const;
        bool lessThan(Album& alb) const;
        //Add, get and remove functions
        bool addSong(Song* s);
        bool addSong(int index, Song* s);
        bool getSong(const string& title, Song** s) const;
        bool getSong(int index, Song** s) const;
        bool removeSong(const string& title, Song**);
        bool removeSong(int index, Song**);
        //Print
        void print() const;
        void printShort() const;
    private:
        string artist;
        string title;
        SongArray* songs;
};

#endif