#include "Artist.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Artist::Artist(string name) : name(name), numberOfAlbums(0), numberOfSongs(0) {}

Artist::Artist(string name, int numberOfAlbums, int numberOfSongs, vector<Song> songs) : name(name), numberOfAlbums(numberOfAlbums), numberOfSongs(numberOfSongs), songs(songs) {}

void Artist::printInfo() {
	cout << "Artist Name: " << name << endl;
	cout << "Number of Albums: " << numberOfAlbums << endl;
	cout << "Number of Songs: " << numberOfSongs << endl;
	cout << "Songs: ";
	for (const auto& song : songs) {
		cout << song.getTitle() << ", ";
	}
	cout << endl;
}
void Artist::setSongs(const vector<Song>& songs) {
	this->songs = songs;
}
string Artist::getName() const { return name; }
int Artist::getNumberOfAlbums() const { return numberOfAlbums; }
int Artist::getNumberOfSongs() const { return numberOfSongs; }
vector<Song> Artist::getSongs() const { return songs; }
void Artist::setName(string name) { this->name = name; }
void Artist::setNumberOfAlbums(int numberOfAlbums) { this->numberOfAlbums = numberOfAlbums; }
void Artist::setNumberOfSongs(int numberOfSongs) { this->numberOfSongs = numberOfSongs; }




vector<Playlist> Artist::getPlaylists() const {
	return playlists;
}

void Artist::addPlaylist(const Playlist& playlist) {
	playlists.push_back(playlist);
}

void Artist::addSong(const Song& song) {
	songs.push_back(song);
	numberOfSongs++;
}

void Artist::viewPlaylists() const {
	cout << "Playlists by " << name << ":" << endl;
	if (playlists.empty()) {
		cout << "  (No playlists added to this artist yet)" << endl;
	} else {
		for (const auto& playlist : playlists) {
			cout << "  - " << playlist.getName() << endl;
		}
	}
}