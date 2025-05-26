#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Song.h"
#include "Playlist.h"
class Artist
{
private:
	string name;
	int numberOfAlbums;
	int numberOfSongs;
	vector<Song> songs;
	vector<Playlist> playlists;
public:
	Artist(string name);
	Artist(string name, int numberOfAlbums, int numberOfSongs, vector<Song> songs);
	string getName() const;
	int getNumberOfAlbums() const;
	int getNumberOfSongs() const;	
	vector<Song> getSongs() const;
	vector<Playlist> getPlaylists() const;
	void setName(string name);
	void setNumberOfAlbums(int numberOfAlbums);
	void setNumberOfSongs(int numberOfSongs);
	void setSongs(const vector<Song>& songs);
	void printInfo();
	void addPlaylist(const Playlist& playlist);
	void addSong(const Song& song);
	void viewPlaylists() const;
};

