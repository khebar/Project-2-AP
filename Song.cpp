#include "Song.h"
#include <iostream>
#include <string>
using namespace std;


string Song::getTitle() const {
	return title;
}
string Song::getArtist() const {
	return artist;
}
int Song::getReleaseYear() const {
	return releaseYear;
}
string Song::getGenre() const {
	return genre;
}
void Song::displayInfo() const {
	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Release Year: " << releaseYear << endl;
	cout << "Genre: " << genre << endl;
}
void Song::setTitle(const string& t) {
	title = t;
}
void Song::setArtist(const string& a) {
	artist = a;
}
void Song::setReleaseYear(int r) {
	releaseYear = r;
}
void Song::setGenre(const string& g) {
	genre = g;
}