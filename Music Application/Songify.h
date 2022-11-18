
#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include <iomanip>

#include "AlbumArray.h"

using namespace std;

class Songify{
    public:
        //Constructors and destructors
        Songify();
        ~Songify();
        //Adding and removing functions
        bool addAlbum(const string& artist, const string& albumTitle);
        bool removeAlbum(const string& artist, const string& albumTitle);
        bool addSong(const string& albumTitle, Song s);
        bool removeSong(const string& artist, const string& albumTitle, const string& songTitle);
        //Client Services
        bool downloadAlbum(const string& artist, const string& albumTitle, Album** a);
        bool streamSong(const string& artist, const string& albumTitle, const string& songTitle, Song** s);
        //Print
        void printAlbums() const;
        void printSongs() const;
    private:
        AlbumArray* albums;
};

#endif