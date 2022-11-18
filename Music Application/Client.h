#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Songify.h"

using namespace std;

class Client{
    public:
        //Constructors and destructors
        Client();
        ~Client();

        //Client services
        bool download(Songify* s, const string& artist, const string& albumTitle) const;
        bool stream(Songify* s, const string& artist, const string& albumTitle, const string& songTitle) const;
        bool playLocal(const string& artist, const string& albumTitle, const string& songTitle) const;
        void printAlbums() const;
        void printSongs() const;
    private:
        AlbumArray* albums;
};

#endif