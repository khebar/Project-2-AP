#include "User.h"
#include <iostream>
using namespace std;
void User::likeSong( Song& song) {
	likedSongs.push_back(song);
	cout << "Liked song: " << song.getTitle() << endl;
}
void User::saveSong( Song& song) {
	savedSongs.push_back(song);
	cout << "Saved song: " << song.getTitle() << endl;
}
void User::displayLikedSongs() const {
	if (likedSongs.empty()) {
		cout << "You have no liked songs." << endl;
		return;
	}
	for (const Song& song : likedSongs) {
		cout << song.getTitle() << endl;
	}
}
void User::displaySavedSongs() const {
	for (auto& song : savedSongs) {
		cout << song.getTitle() << endl;
	}
}
 void User::createPlaylist(const string& playlistName) {
 	Playlist newPlaylist(playlistName);
 	userPlaylists.push_back(newPlaylist);
 	cout << "Playlist '" << playlistName << "' created successfully!" << endl;
 }
 void User::addSongToPlaylist(const string& playlistName, const Song& song) {
 	for (Playlist& playlist : userPlaylists) {
 		if (playlist.getName() == playlistName) {
 			playlist.addSong(song); // Pass the Song object directly
 			cout << "Song '" << song.getTitle() << "' added to playlist '" << playlistName << "'" << endl;
 			return;
 		}
 	}
 	cout << "Playlist '" << playlistName << "' not found!" << endl;
 }
 void User::removeSongFromPlaylist(const string& playlistName, const string& songTitle) {
 	for (Playlist& playlist : userPlaylists) {
 		if (playlist.getName() == playlistName) {
 			playlist.removeSong(songTitle);
 			cout << "Song '" << songTitle << "' removed from playlist '" << playlistName << "'" << endl;
 			return;
 		}
 	}
 	cout << "Playlist '" << playlistName << "' not found!" << endl;
 }
 void User::viewPlaylists() const {
 	if (userPlaylists.empty()) {
 		cout << "You have no playlists." << endl;
 		return;
 	}
 	for (const Playlist& playlist : userPlaylists) {
 		cout << "- " << playlist.getName() << " (" << playlist.getNumberOfSongs() << " songs)" << endl;
 	}
 }
 void User::removePlaylist(const string& playlistName) {
 	for (vector<Playlist>::iterator it = userPlaylists.begin(); it != userPlaylists.end(); ++it) {
 		if (it->getName() == playlistName) {
 			userPlaylists.erase(it);
 			cout << "Playlist '" << playlistName << "' removed successfully!" << endl;
 			return;
 		}
 	}
 	cout << "Playlist '" << playlistName << "' not found!" << endl;
 }
 void User::likePlaylist(const Playlist& playlist) {
 	likedPlaylists.push_back(playlist);
 	cout << "Playlist '" << playlist.getName() << "' added to liked playlists!" << endl;
 }
 void User::viewLikedPlaylists() const {
 	if (likedPlaylists.empty()) {
 		cout << "You have no liked playlists." << endl;
 		return;
 	}
 	cout << "Your Liked Playlists:" << endl;
 	for (const Playlist& playlist : likedPlaylists) {
 		cout << "- " << playlist.getName() << " (" << playlist.getNumberOfSongs() << " songs)" << endl;
 	}
 }
 void User::viewAllSongs(const vector<Song>& allSongs) const {
     if (allSongs.empty()) {
         cout << "No songs available." << endl;
         return;
     }
 }
