#include "Playlist.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Playlist::addSong(const Song& song){
	songs.push_back(song);
	cout << "Song '" << song.getTitle() << "' added to the playlist '" << name << "'." << endl;
	numberOfSongs = songs.size();
}

void Playlist::removeSong(const string& songTitle) {
	for (auto it = songs.begin(); it != songs.end(); ++it) {
		if (it->getTitle() == songTitle) {
			songs.erase(it);
			numberOfSongs = songs.size();
			cout << "Song '" << songTitle << "' removed from the playlist '" << name << "'." << endl;
			return;
		}
	}
	cout << "Song '" << songTitle << "' not found in the playlist '" << name << "'." << endl;
}

void Playlist::playSong(const string& songTitle) {
	cout << "Playing song: " << songTitle << " from playlist " << name << endl;
}

vector<Song> Playlist::getSongs() const {
	return songs;
}

string Playlist::getName() const {
	return name;
}

void Playlist::setName(const string& newName) {
	name = newName;
}

int Playlist::getNumberOfSongs() const {
	
	return songs.size();
}

Playlist::Playlist(const string& name) : name(name) {
	numberOfSongs = 0;
}
void Playlist::displayPlaylist() const {
	for (const auto& song : songs) {
		cout << "  - " << song.getTitle() << " by " << song.getArtist() << endl;
	}
}
