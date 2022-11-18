
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <iomanip>

#include "defs.h"

using namespace std;

class Song{
    public:
        //Constructors and destructors
        Song(const string& artist, const string& title, const string& content);
        Song();
        Song(Song& s);
        //Getters
        string getArtist() const;
        string getTitle() const;
        //Comparative function
        bool matches(const string& artist, const string& title) const;
        //Print
        void print() const;
        void play() const;
    private:
        string artist;
        string title;
        string content;
};

#endif