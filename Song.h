#pragma once
#include <iostream>
#include <string>
using namespace std;
class Song
{
private:
	string title;
	string artist;
	int releaseYear;
	string genre;
public:
	Song(string title, string artist, int releaseYear, string genre) : title(title), artist(artist), releaseYear(releaseYear), genre(genre) {}
	string getTitle() const;
	string getArtist() const;
	int getReleaseYear() const;
	string getGenre() const;
	void setTitle(const string& title);
	void setArtist(const string& artist);
	void setReleaseYear(const int releaseYear);
	void setGenre(const string& genre);
	void displayInfo() const;
};



