
#include "Song.h"

Song::Song(const string& a, const string& t, const string& c){
    artist = a;
    title = t;
    content = c;
}

Song::Song(){
    artist = "UNKNOWN ARTIST";
    title = "UNKNOWN SONG NAME";
    content = "UNKNOWN CONTENT";
}

Song::Song(Song& s): artist(s.artist), title(s.title), content(s.content){
}

string Song::getArtist() const{
    return artist;
}

string Song::getTitle() const{
    return title;
}

bool Song::matches(const string& art, const string& tit) const{
    if (artist != art){
        return false;
    }
    if (title != tit){
        return false;
    }
    return true;
}

void Song::print() const{
    cout<<"Song Artist :"<<artist<<" Title:"<<title<<endl;
}

void Song::play() const{
    cout<<"Song Artist :"<<artist<<" Title:"<<title<<" \n Content: \n"<<content<<endl;
}