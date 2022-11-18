
#include "Songify.h"

Songify::Songify(): albums(new AlbumArray()){
}


Songify::~Songify(){
    delete albums;
}

bool Songify::addAlbum(const string& artist, const string& albumTitle){
    if ((*albums).size() < MAX_ARRAY){
        Album* newAlbum = new Album(artist, albumTitle);
        (*albums).add(newAlbum);
        return true;
    }
    cout<<"Add Failed"<<endl;
    return false;
}


bool Songify::removeAlbum(const string& artist, const string& albumTitle){
    Album* temp;
    if ((*albums).remove(artist, albumTitle, &temp)){
        delete temp;
        return true;
    }
    delete temp;
    cout<<"Remove Failed"<<endl;
    return false;
}

bool Songify::addSong(const string& albumTitle, Song s){
    Album* temp;
    for (int i = 0; i<albums->size(); i++){
        (*albums).get(i, &temp);
        if ((*temp).getTitle() == albumTitle){
            Song* newSong = new Song(s);
            temp->addSong(newSong);
            return true;
        }
    }
    cout<<"Add Failed"<<endl;
    return false;
}

bool Songify::removeSong(const string& artist, const string& albumTitle, const string& songTitle){
    //Create temp album
    Album* temp;
    //If the album exists
    if ((*albums).get(artist, albumTitle, &temp)){
        Song* tempSong;
        //Search the album for the song
        if (temp->removeSong(songTitle, &tempSong)){
            delete tempSong;
            return true;
        }
        delete tempSong;
    }
    cout<<"Remove Failed"<<endl;
    return false;    
}

bool Songify::downloadAlbum(const string& artist, const string& albumTitle, Album** a){
    return (*albums).get(artist, albumTitle, a);
}

bool Songify::streamSong(const string& artist, const string& albumTitle, const string& songTitle, Song** s){
    Album* a;
    (*albums).get(artist, albumTitle, &a);
    return a->getSong(songTitle, s);
}

void Songify::printAlbums() const{
    (*albums).printShort();
}

void Songify::printSongs() const{
    cout<<"Songify"<<endl;
    (*albums).print();
}