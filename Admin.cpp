#include "Admin.h"
#include "Song.h"
#include "Playlist.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Admin::setUsername(const string& user) {
    username = user;
}
void Admin::setPassword(const string& pass) {
    password = pass;
}
string Admin::getUsername() const {
    return this->username;
}
string Admin::getPassword() const {
    return this->password;
}
void Admin::addSong(const Song& song, vector<Song>& songs){
    songs.push_back(song);
}
void Admin::removeSong(const string& songName, vector<Song>& songs) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->getTitle() == songName) {
            songs.erase(it);
			cout << "Song removed successfully." << endl;
            return;
        }
    }
    cout << "Song not found." << endl;
}
void Admin::addPlaylist(const Playlist& playlist, vector<Playlist>& playlists) {
    playlists.push_back(playlist);
}
