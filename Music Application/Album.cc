
#include "Album.h"
#include <cstring>

Album::Album(const string& art, const string& tit){
    artist = art;
    title = tit;
    songs = new SongArray;
}

Album::Album(Album& alb): artist(alb.artist), title(alb.title), songs(new SongArray(*alb.songs)){
  cout<<"Copy called"<<endl;
}

Album::~Album(){
    delete songs;
}

string Album::getArtist() const{
    return artist;
}

string Album::getTitle() const{
    return title;
}

bool Album::matches(const string& art, const string& tit) const{
    if (artist != art){
        return false;
    }
    if (title != tit){
        return false;
    }
    return true;
}

bool Album::lessThan(Album& alb) const{
    if (artist == alb.artist){
        return title < alb.title;
    }
    return artist < alb.artist;
}

bool Album::addSong(Song* s){
    if (s->getArtist() != artist){
        return false;
    }
    return (*songs).add(s);
}

bool Album::addSong(int index, Song* s){
    if (s->getArtist() != artist){
        return false;
    }
    return (*songs).add(index, s);
}

bool Album::getSong(const string& tit, Song** s) const{
    return (*songs).get(artist, tit, s);
}

bool Album::getSong(int index, Song** s) const{
    return (*songs).get(index, s);
}

bool Album::removeSong(const string& tit, Song** s){
    return (*songs).remove(artist, tit, s);
}

bool Album::removeSong(int index, Song** s){
    return (*songs).remove(index, s);
}

void Album::print() const{
    cout<<"Album"<<endl;
    cout<<"Album Artist: "<<artist<<" Title: "<<title<<endl;
    (*songs).print();
}

void Album::printShort() const{
    cout<<"Album Artist: "<<artist<<" Title: "<<title<<endl;
}