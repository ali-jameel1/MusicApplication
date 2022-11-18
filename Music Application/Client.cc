
#include "Client.h"

Client::Client(): albums(new AlbumArray()){

}

Client::~Client(){
    delete albums;
}

bool Client::download(Songify* s, const string& artist, const string& albumTitle) const{
    Album* album;
    if(s->downloadAlbum(artist, albumTitle, &album)){
        Album* copy = new Album(*album);
        if((*albums).add(copy)){
            return true;
        }else{
            delete copy;
        }
    }
    return false;
}


bool Client::stream(Songify* s, const string& artist, const string& albumTitle, const string& songTitle) const{
    Song* song;
    if ((*s).streamSong(artist, albumTitle, songTitle, &song)){
        (*song).play();
        return true;
    }
    return false;
}

bool Client::playLocal(const string& artist, const string& albumTitle, const string& songTitle) const{
    Album* album;
    if ((*albums).get(artist, albumTitle, &album)){
        Song* song;
        if ((*album).getSong(songTitle, &song)){
            (*song).play();
            return true;
        }
    }
    return false;
}

void Client::printAlbums() const{
    (*albums).printShort();
}

void Client::printSongs() const{
    (*albums).print();
}