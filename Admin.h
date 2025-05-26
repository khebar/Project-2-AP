#pragma once
#include "PUser.h"
#include "Song.h"
#include "Playlist.h"
#include <iostream> 
#include <string>
#include <vector>
using namespace std;
class Admin :
    public PUser
{
private:
    string username;
    string password;
public:
	Admin() = default;
	Admin(const string& user, const string& pass) : PUser(user,pass), username(user), password(pass) {}
    void setUsername(const string& user);
    void setPassword(const string& pass);
    string getUsername() const;
    string getPassword() const;
	void addSong(const Song& song, vector<Song>& songs);
	void displayPlaylist() const;
    void removeSong(const string& song, vector<Song>& songs);
	void addPlaylist(const Playlist& playlist, vector<Playlist>& playlists);
	void addSongToPlaylist(const string& song, const string& playlistName, vector<Playlist>& playlists, vector<Song>& songs);
	void removeSongFromPlaylist(const string& song, const string& playlistName, vector<Playlist>& playlists);
};

