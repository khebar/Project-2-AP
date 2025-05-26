#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "Song.h"
class Playlist
{
private:
    vector<Song> songs;
    string name;
    int numberOfSongs;

public:
    void addSong(const Song& song);
    void removeSong(const string& songTitle);
    void playSong(const string& songTitle);
    vector<Song> getSongs() const;
    string getName() const;
    void setName(const string& newName);
    int getNumberOfSongs() const;
    Playlist(const string& name = "Untitled Playlist");
    ~Playlist() = default;
    void displayPlaylist() const;
};

