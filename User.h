#pragma once
#include "PUser.h"
#include "Song.h"
#include "Playlist.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class User :
    public PUser
{
private:
	vector <Song> likedSongs;
	vector <Song> savedSongs;
	vector <Playlist> userPlaylists;
	vector <Playlist> likedPlaylists;
public:
	User(string u, string p) : PUser(u, p) {}
	void displayUser();
	void likeSong( Song& song);
	void saveSong( Song& song);
	void displayLikedSongs() const;
	void displaySavedSongs() const;
	 void createPlaylist(const string& playlistName);
	 void addSongToPlaylist(const string& playlistName, const Song& song);
	 void removeSongFromPlaylist(const string& playlistName, const string& songTitle);
	 void viewPlaylists() const;
	 void removePlaylist(const string& playlistName);
	 void likePlaylist(const Playlist& playlist);
	 void viewLikedPlaylists() const;
	 void viewAllSongs(const vector<Song>& allSongs) const;
	
};

