


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <limits>
using namespace std;
#include "Song.h"
#include "Admin.h"
#include "Artist.h"
#include "Playlist.h"
#include "User.h"

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidChoice(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cout << "Invalid input! Please enter a number between " << min << " and " << max << ": ";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return choice;
        }
    }
}

bool searchUser(const vector<User>& users, const string& username) {
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

int searchUserIndex(const vector<User>& users, const string& username) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username) {
            return i;
        }
    }
    return -1;
}

bool authenticateUser(const vector<User>& users, const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }
    return false;
}

bool isValidSongChoice(int choice, int maxSize) {
    return choice > 0 && choice <= maxSize;
}

vector<Song> filterSongsByArtist(const vector<Song>& songs, const string& artist) {
    vector<Song> filtered;
    for (const auto& song : songs) {
        if (song.getArtist() == artist) {
            filtered.push_back(song);
        }
    }
    return filtered;
}

vector<Song> filterSongsByYear(const vector<Song>& songs, int year) {
    vector<Song> filtered;
    for (const auto& song : songs) {
        if (song.getReleaseYear() == year) {
            filtered.push_back(song);
        }
    }
    return filtered;
}

vector<Song> filterSongsByGenre(const vector<Song>& songs, const string& genre) {
    vector<Song> filtered;
    for (const auto& song : songs) {
        if (song.getGenre() == genre) {
            filtered.push_back(song);
        }
    }
    return filtered;
}

vector<Song> sortSongsByTitle(vector<Song> songs) {
    sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
        return a.getTitle() < b.getTitle();
        });
    return songs;
}

vector<Song> sortSongsByArtist(vector<Song> songs) {
    sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
        return a.getArtist() < b.getArtist();
        });
    return songs;
}

vector<Song> sortSongsByYear(vector<Song> songs) {
    sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
        return a.getReleaseYear() < b.getReleaseYear();
        });
    return songs;
}

vector<Song> sortSongsByGenre(vector<Song> songs) {
    sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
        return a.getGenre() < b.getGenre();
        });
    return songs;
}

void playInteractiveSongs(const vector<Song>& playlist, bool loopMode = false) {
    if (playlist.empty()) {
        cout << "No songs to play!" << endl;
        return;
    }

    int currentIndex = 0;
    bool playing = true;

    while (playing) {
        const Song& currentSong = playlist[currentIndex];
        cout << "\n=== NOW PLAYING ===" << endl;
        cout << "♪ Title: " << currentSong.getTitle() << endl;
        cout << "♪ Artist: " << currentSong.getArtist() << endl;
        cout << "♪ Year: " << currentSong.getReleaseYear() << endl;
        cout << "♪ Genre: " << currentSong.getGenre() << endl;
        cout << "♪ Track: " << (currentIndex + 1) << "/" << playlist.size() << endl;
        cout << "===================" << endl;

        cout << "\nPlayer Controls:" << endl;
        cout << "1. Previous Song" << endl;
        cout << "2. Next Song" << endl;
        cout << "3. Replay Current Song" << endl;
        cout << "4. Toggle Loop Mode (" << (loopMode ? "ON" : "OFF") << ")" << endl;
        cout << "0. Stop Playing" << endl;
        cout << "Enter your choice: ";

        int choice = getValidChoice(0, 4);

        switch (choice) {
        case 0:
            playing = false;
            cout << "Stopped playing." << endl;
            break;
        case 1:
            if (currentIndex > 0) {
                currentIndex--;
            }
            else if (loopMode) {
                currentIndex = playlist.size() - 1;
            }
            else {
                cout << "Already at the first song!" << endl;
            }
            break;
        case 2:
            if (currentIndex < playlist.size() - 1) {
                currentIndex++;
            }
            else if (loopMode) {
                currentIndex = 0;
            }
            else {
                cout << "Already at the last song!" << endl;
            }
            break;
        case 3:
            cout << "Replaying current song..." << endl;
            break;
        case 4:
            loopMode = !loopMode;
            cout << "Loop mode " << (loopMode ? "enabled" : "disabled") << "." << endl;
            break;
        }
    }
}

vector<Song> handleFilterSort(const vector<Song>& allSongs) {
    vector<Song> result = allSongs;

    cout << "\n=== FILTER & SORT OPTIONS ===" << endl;
    cout << "1. Filter by Artist" << endl;
    cout << "2. Filter by Year" << endl;
    cout << "3. Filter by Genre" << endl;
    cout << "4. Sort by Title (A-Z)" << endl;
    cout << "5. Sort by Artist (A-Z)" << endl;
    cout << "6. Sort by Year" << endl;
    cout << "7. Sort by Genre" << endl;
    cout << "0. No Filter/Sort" << endl;
    cout << "Enter your choice: ";

    int choice = getValidChoice(0, 7);

    switch (choice) {
    case 1: {
        string artist;
        cout << "Enter artist name: ";
        getline(cin, artist);
        result = filterSongsByArtist(allSongs, artist);
        break;
    }
    case 2: {
        int year;
        cout << "Enter year: ";
        year = getValidChoice(1900, 2024);
        result = filterSongsByYear(allSongs, year);
        break;
    }
    case 3: {
        string genre;
        cout << "Enter genre: ";
        getline(cin, genre);
        result = filterSongsByGenre(allSongs, genre);
        break;
    }
    case 4:
        result = sortSongsByTitle(allSongs);
        break;
    case 5:
        result = sortSongsByArtist(allSongs);
        break;
    case 6:
        result = sortSongsByYear(allSongs);
        break;
    case 7:
        result = sortSongsByGenre(allSongs);
        break;
    case 0:
    default:
        result = allSongs;
        break;
    }

    cout << "\nFiltered/Sorted Results (" << result.size() << " songs):" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << ". " << result[i].getTitle() << " by " << result[i].getArtist()
            << " (" << result[i].getReleaseYear() << ", " << result[i].getGenre() << ")" << endl;
    }

    return result;
}

void displayMainMenu() {
    cout << "\n=== MUSIC PLAYER APP ===" << endl;
    cout << "1. Login as User" << endl;
    cout << "2. Login as Admin" << endl;
    cout << "3. Register New User" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Enter your choice: ";
}

void displayAdminMenu() {
    cout << "\n=== ADMIN MENU ===" << endl;
    cout << "1. Add Song" << endl;
    cout << "2. Remove Song" << endl;
    cout << "3. View All Songs" << endl;
    cout << "4. Add Artist" << endl;
    cout << "5. Add Playlist to Artist" << endl;
    cout << "6. Add Song to Artist" << endl;
    cout << "7. View All Artists" << endl;
    cout << "8. Edit Artist" << endl;
    cout << "0. Logout" << endl;
    cout << "Enter your choice: ";
}

void displayUserMenu() {
    cout << "\n=== USER MENU ===" << endl;
    cout << "1. Create Playlist" << endl;
    cout << "2. Add Song to Playlist" << endl;
    cout << "3. Remove Song from Playlist" << endl;
    cout << "4. View My Playlists" << endl;
    cout << "5. View Liked Songs" << endl;
    cout << "6. View Saved Songs" << endl;
    cout << "7. View All Songs" << endl;
    cout << "8. Like Song" << endl;
    cout << "9. Save Song" << endl;
    cout << "10. Play Songs (Interactive)" << endl;
    cout << "11. Remove Playlist" << endl;
    cout << "12. View all Artists" << endl;
    cout << "13. Filter/Sort & Play Songs" << endl;
    cout << "0. Logout" << endl;
    cout << "Enter your choice: ";
}

void handleAddSong(vector<Song>& allSongs) {
    string title, artistName, genre;
    int year;

    cout << "Enter song title: ";
    getline(cin, title);
    if (title.empty()) {
        cout << "Song title cannot be empty!" << endl;
        return;
    }

    cout << "Enter artist name: ";
    getline(cin, artistName);
    if (artistName.empty()) {
        cout << "Artist name cannot be empty!" << endl;
        return;
    }

    cout << "Enter release year: ";
    year = getValidChoice(1900, 2024);

    cout << "Enter genre: ";
    getline(cin, genre);
    if (genre.empty()) {
        cout << "Genre cannot be empty!" << endl;
        return;
    }

    allSongs.push_back(Song(title, artistName, year, genre));
    cout << "Song '" << title << "' added successfully!" << endl;
}

void handleRemoveSong(vector<Song>& allSongs) {
    if (allSongs.empty()) {
        cout << "No songs to remove." << endl;
        return;
    }

    cout << "\nAll Songs:" << endl;
    for (int i = 0; i < allSongs.size(); ++i) {
        cout << i + 1 << ". " << allSongs[i].getTitle() << " by " << allSongs[i].getArtist() << endl;
    }

    cout << "Enter song number to remove (0 to cancel): ";
    int songIndex = getValidChoice(0, allSongs.size());

    if (songIndex == 0) {
        cout << "Operation cancelled." << endl;
        return;
    }

    string removedTitle = allSongs[songIndex - 1].getTitle();
    allSongs.erase(allSongs.begin() + (songIndex - 1));
    cout << "Song '" << removedTitle << "' removed successfully!" << endl;
}

void handleViewAllSongs(const vector<Song>& allSongs) {
    cout << "\n=== ALL SONGS ===" << endl;
    if (allSongs.empty()) {
        cout << "No songs available." << endl;
        return;
    }

    for (const auto& song : allSongs) {
        cout << "• " << song.getTitle() << " by " << song.getArtist()
            << " (" << song.getReleaseYear() << ", " << song.getGenre() << ")" << endl;
    }
}

void handleAddArtist(vector<Artist>& artists) {
    string artistName;
    cout << "Enter artist name: ";
    getline(cin, artistName);

    if (artistName.empty()) {
        cout << "Artist name cannot be empty!" << endl;
        return;
    }

    for (const auto& artist : artists) {
        if (artist.getName() == artistName) {
            cout << "Artist '" << artistName << "' already exists!" << endl;
            return;
        }
    }

    artists.push_back(Artist(artistName));
    cout << "Artist '" << artistName << "' added successfully!" << endl;
}

bool adminLogin(const Admin& admin) {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;
    clearInputBuffer();

    return (username == admin.getUsername() && password == admin.getPassword());
}

bool userLogin(const vector<User>& users, string& username) {
    string password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    clearInputBuffer();

    return authenticateUser(users, username, password);
}

bool registerUser(vector<User>& users) {
    string username, password;
    cout << "Enter desired username: ";
    cin >> username;

    if (searchUser(users, username)) {
        cout << "Username already exists! Please choose a different username." << endl;
        clearInputBuffer();
        return false;
    }

    cout << "Enter password: ";
    cin >> password;
    clearInputBuffer();

    if (username.empty() || password.empty()) {
        cout << "Username and password cannot be empty!" << endl;
        return false;
    }

    users.push_back(User(username, password));
    cout << "User '" << username << "' registered successfully!" << endl;
    return true;
}

int main() {
    cout << "=== WELCOME TO MUSIC PLAYER APP ===" << endl;
    cout << "=====================================" << endl;

    vector<User> users;
    vector<Song> allSongs;
    vector<Artist> artists;

    allSongs.push_back(Song("Shape of You", "Ed Sheeran", 2017, "Pop"));
    allSongs.push_back(Song("Blinding Lights", "The Weeknd", 2019, "Synthpop"));
    allSongs.push_back(Song("Bohemian Rhapsody", "Queen", 1975, "Rock"));
    allSongs.push_back(Song("Imagine", "John Lennon", 1971, "Rock"));
    allSongs.push_back(Song("Hotel California", "Eagles", 1976, "Rock"));

    Admin admin("admin", "admin123");

    while (true) {
        displayMainMenu();
        int mainChoice = getValidChoice(0, 3);

        switch (mainChoice) {
        case 0: {
            cout << "\nThank you for using Music Player App!" << endl;
            cout << "Goodbye!" << endl;
            return 0;
        }

        case 1: {
            string username;
            if (!userLogin(users, username)) {
                cout << "Invalid username or password!" << endl;
                break;
            }

            cout << "Welcome, " << username << "!" << endl;
            int userIndex = searchUserIndex(users, username);
            User& currentUser = users[userIndex];

            bool userLoggedIn = true;
            while (userLoggedIn) {
                displayUserMenu();
                int userChoice = getValidChoice(0, 13);

                switch (userChoice) {
                case 0: {
                    cout << "Logging out..." << endl;
                    userLoggedIn = false;
                    break;
                }

                case 1: {
                    string playlistName;
                    cout << "Enter playlist name: ";
                    getline(cin, playlistName);
                    if (!playlistName.empty()) {
                        currentUser.createPlaylist(playlistName);
                    }
                    else {
                        cout << "Playlist name cannot be empty!" << endl;
                    }
                    break;
                }

                case 2: {
                    string playlistName;
                    cout << "Enter playlist name: ";
                    getline(cin, playlistName);

                    if (allSongs.empty()) {
                        cout << "No songs available!" << endl;
                        break;
                    }

                    cout << "\nAvailable songs:" << endl;
                    for (int i = 0; i < allSongs.size(); i++) {
                        cout << i + 1 << ". " << allSongs[i].getTitle() << " by " << allSongs[i].getArtist() << endl;
                    }

                    cout << "Enter song number to add (0 to cancel): ";
                    int songChoice = getValidChoice(0, allSongs.size());

                    if (songChoice > 0) {
                        currentUser.addSongToPlaylist(playlistName, allSongs[songChoice - 1]);
                    }
                    else {
                        cout << "Operation cancelled." << endl;
                    }
                    break;
                }

                case 3: {
                    string playlistName, songTitle;
                    cout << "Enter playlist name: ";
                    getline(cin, playlistName);
                    cout << "Enter song title to remove: ";
                    getline(cin, songTitle);
                    currentUser.removeSongFromPlaylist(playlistName, songTitle);
                    break;
                }

                case 4: {
                    cout << "\n=== YOUR PLAYLISTS ===" << endl;
                    currentUser.viewPlaylists();
                    break;
                }

                case 5: {
                    cout << "\n=== YOUR LIKED SONGS ===" << endl;
                    currentUser.displayLikedSongs();
                    break;
                }

                case 6: {
                    cout << "\n=== YOUR SAVED SONGS ===" << endl;
                    currentUser.displaySavedSongs();
                    break;
                }

                case 7: {
                    handleViewAllSongs(allSongs);
                    break;
                }

                case 8: {
                    if (allSongs.empty()) {
                        cout << "No songs available to like!" << endl;
                        break;
                    }

                    cout << "\nAvailable songs to like:" << endl;
                    for (int i = 0; i < allSongs.size(); i++) {
                        cout << i + 1 << ". " << allSongs[i].getTitle() << " by " << allSongs[i].getArtist() << endl;
                    }

                    cout << "Enter song number to like (0 to cancel): ";
                    int songChoice = getValidChoice(0, allSongs.size());

                    if (songChoice > 0) {
                        currentUser.likeSong(allSongs[songChoice - 1]);
                    }
                    else {
                        cout << "Operation cancelled." << endl;
                    }
                    break;
                }

                case 9: {
                    if (allSongs.empty()) {
                        cout << "No songs available to save!" << endl;
                        break;
                    }

                    cout << "\nAvailable songs to save:" << endl;
                    for (int i = 0; i < allSongs.size(); i++) {
                        cout << i + 1 << ". " << allSongs[i].getTitle() << " by " << allSongs[i].getArtist() << endl;
                    }

                    cout << "Enter song number to save (0 to cancel): ";
                    int songChoice = getValidChoice(0, allSongs.size());

                    if (songChoice > 0) {
                        currentUser.saveSong(allSongs[songChoice - 1]);
                    }
                    else {
                        cout << "Operation cancelled." << endl;
                    }
                    break;
                }

                case 10: {
                    playInteractiveSongs(allSongs);
                    break;
                }

                case 11: {
                    string playlistName;
                    cout << "Enter playlist name to remove: ";
                    getline(cin, playlistName);
                    if (!playlistName.empty()) {
                        currentUser.removePlaylist(playlistName);
                    }
                    else {
                        cout << "Playlist name cannot be empty!" << endl;
                    }
                    break;
                }

                case 12: {
                    cout << "\n=== ALL ARTISTS ===" << endl;
                    if (artists.empty()) {
                        cout << "No artists available." << endl;
                    }
                    else {
                        for (const auto& artist : artists) {
                            cout << "\n• Artist: " << artist.getName() << endl;
                            artist.viewPlaylists();
                            cout << "  Songs by " << artist.getName() << ":" << endl;
                            if (artist.getSongs().empty()) {
                                cout << "    (No songs added to this artist yet)" << endl;
                            }
                            else {
                                for (const auto& song : artist.getSongs()) {
                                    cout << "    - " << song.getTitle() << endl;
                                }
                            }
                        }
                    }
                    break;
                }

                case 13: {
                    vector<Song> filteredSongs = handleFilterSort(allSongs);
                    if (!filteredSongs.empty()) {
                        cout << "\nWould you like to play these songs? (y/n): ";
                        char playChoice;
                        cin >> playChoice;
                        clearInputBuffer();
                        if (playChoice == 'y' || playChoice == 'Y') {
                            playInteractiveSongs(filteredSongs);
                        }
                    }
                    break;
                }

                default: {
                    cout << "Invalid choice! Please try again." << endl;
                    break;
                }
                }
            }
            break;
        }

        case 2: {
            if (!adminLogin(admin)) {
                cout << "Invalid admin credentials!" << endl;
                break;
            }

            cout << "Admin access granted!" << endl;
            bool adminLoggedIn = true;

            while (adminLoggedIn) {
                displayAdminMenu();
                int adminChoice = getValidChoice(0, 8);

                switch (adminChoice) {
                case 0: {
                    cout << "Admin logged out." << endl;
                    adminLoggedIn = false;
                    break;
                }

                case 1: {
                    handleAddSong(allSongs);
                    break;
                }

                case 2: {
                    handleRemoveSong(allSongs);
                    break;
                }

                case 3: {
                    handleViewAllSongs(allSongs);
                    break;
                }

                case 4: {
                    handleAddArtist(artists);
                    break;
                }

                case 5: {
                    if (artists.empty()) {
                        cout << "No artists available. Add an artist first." << endl;
                        break;
                    }

                    cout << "\nSelect Artist:" << endl;
                    for (int i = 0; i < artists.size(); ++i) {
                        cout << i + 1 << ". " << artists[i].getName() << endl;
                    }

                    cout << "Enter artist number (0 to cancel): ";
                    int artistChoice = getValidChoice(0, artists.size());

                    if (artistChoice > 0) {
                        string playlistName;
                        cout << "Enter playlist name: ";
                        getline(cin, playlistName);
                        if (!playlistName.empty()) {
                            artists[artistChoice - 1].addPlaylist(Playlist(playlistName));
                            cout << "Playlist '" << playlistName << "' added to artist '"
                                << artists[artistChoice - 1].getName() << "'." << endl;
                        }
                        else {
                            cout << "Playlist name cannot be empty!" << endl;
                        }
                    }
                    break;
                }

                case 6: {
                    if (artists.empty()) {
                        cout << "No artists available. Add an artist first." << endl;
                        break;
                    }
                    if (allSongs.empty()) {
                        cout << "No songs available. Add songs first." << endl;
                        break;
                    }

                    cout << "\nSelect Artist:" << endl;
                    for (int i = 0; i < artists.size(); ++i) {
                        cout << i + 1 << ". " << artists[i].getName() << endl;
                    }

                    cout << "Enter artist number (0 to cancel): ";
                    int artistChoice = getValidChoice(0, artists.size());

                    if (artistChoice > 0) {
                        cout << "\nSelect Song to Add:" << endl;
                        for (int i = 0; i < allSongs.size(); ++i) {
                            cout << i + 1 << ". " << allSongs[i].getTitle() << " by " << allSongs[i].getArtist() << endl;
                        }

                        cout << "Enter song number (0 to cancel): ";
                        int songChoice = getValidChoice(0, allSongs.size());

                        if (songChoice > 0) {
                            artists[artistChoice - 1].addSong(allSongs[songChoice - 1]);
                            cout << "Song '" << allSongs[songChoice - 1].getTitle()
                                << "' added to artist '" << artists[artistChoice - 1].getName() << "'." << endl;
                        }
                    }
                    break;
                }

                case 7: {
                    cout << "\n=== ALL ARTISTS ===" << endl;
                    if (artists.empty()) {
                        cout << "No artists available." << endl;
                    }
                    else {
                        for (const auto& artist : artists) {
                            cout << "\n• Artist: " << artist.getName() << endl;
                            artist.viewPlaylists();
                            cout << "  Songs by " << artist.getName() << ":" << endl;
                            if (artist.getSongs().empty()) {
                                cout << "    (No songs added to this artist yet)" << endl;
                            }
                            else {
                                for (const auto& song : artist.getSongs()) {
                                    cout << "    - " << song.getTitle() << endl;
                                }
                            }
                        }
                    }
                    break;
                }

                case 8: {
                    if (artists.empty()) {
                        cout << "No artists to edit." << endl;
                        break;
                    }

                    cout << "\nSelect Artist to Edit:" << endl;
                    for (int i = 0; i < artists.size(); ++i) {
                        cout << i + 1 << ". " << artists[i].getName() << endl;
                    }

                    cout << "Enter artist number (0 to cancel): ";
                    int artistChoice = getValidChoice(0, artists.size());

                    if (artistChoice > 0) {
                        Artist& selectedArtist = artists[artistChoice - 1];
                        cout << "\nEditing Artist: " << selectedArtist.getName() << endl;
                        cout << "1. Change Name" << endl;
                        cout << "2. Remove Artist" << endl;
                        cout << "0. Cancel" << endl;
                        cout << "Enter your choice: ";

                        int editChoice = getValidChoice(0, 2);
                        switch (editChoice) {
                        case 1: {
                            string newName;
                            cout << "Enter new name: ";
                            getline(cin, newName);
                            if (!newName.empty()) {
                                selectedArtist.setName(newName);
                                cout << "Artist name updated successfully." << endl;
                            }
                            else {
                                cout << "Name cannot be empty!" << endl;
                            }
                            break;
                        }
                        case 2: {
                            string artistName = selectedArtist.getName();
                            artists.erase(artists.begin() + (artistChoice - 1));
                            cout << "Artist '" << artistName << "' removed successfully." << endl;
                            break;
                        }
                        case 0: {
                            cout << "Operation cancelled." << endl;
                            break;
                        }
                        }
                    }
                    break;
                }

                default: {
                    cout << "Invalid choice! Please try again." << endl;
                    break;
                }
                }
            }
            break;
        }

        case 3: {
            registerUser(users);
            break;
        }

        default: {
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}