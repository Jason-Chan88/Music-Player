#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Song.h"
#include "Playlist.h"

using namespace std;

//Constants
const int LOW_YEAR = 2010; //First year of music catalog
const int HIGH_YEAR = 2021; //Last year of music catalog
const string FILE_NAME = "proj3_music.txt"; //Default input file
const char DELIMITER = '|'; //Default delimiter for the input file

class MusicPlayer{
public:
    //Name: MusicPlayer - Default Constructor
    //Precondition: None
    //Postcondition: Dynamically creates a new MusicPlayer and populates m_filename FILE_NAME
    MusicPlayer();
    //Name: ~MusicPlayer - Destructor
    //Precondition: None
    //Postcondition: Destructs all songs in the catalog and all songs in the playlist
    ~MusicPlayer();
    //Name: LoadCatalog(string filename)
    //Precondition: Requires filename
    //Postcondition: Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
    void LoadCatalog(string filename);
    //Name: MainMenu
    //Precondition: None
    //Postcondition: Manages the application and the menu. Calls until user chooses to quit.
    void MainMenu();
    //Name: CreateNewPlaylist
    //Precondition: none
    //Postcondition: Creates a new playlist object and adds it to the m_playlists vector
    void CreateNewPlaylist();
    //Name: ChoosePlaylist
    //Precondition: need a playlist to exist
    //Postcondition: current playlist is set to user choice if playlist exists
    void ChoosePlaylist();
    //Name: DisplaySongs
    //Precondition: User enters year using constants above (2010-2021)
    //Postcondition: Lists all songs (numbered) for that year by ranking
    void DisplaySongs();
    //Name: AddSong
    //Precondition: m_songCatalog is populated and m_playList exists
    //Postcondition: Displays the songs for a specific year. Adds a song to the m_playList by dynamically allocating a new song based on the song in the catalog
    //               and inserting it in the end.
    //               May have duplicate songs on a playlist.
    //               If the user chooses 2010, the user does not have to choose something from 2010 but it does need to be valid (between 1 - 1200)
    void AddSong();
    //Name: DisplayPlaylist
    //Precondition: None (can be empty)
    //Postcondition: Displays the playlist or tells the user it is empty
    void DisplayPlaylist();
    //Name: PlaySong
    //Precondition: Playlist should be populated
    //Postcondition: Allows the user to choose a song from the playlist to play.
    //               Removes chosen song from playlist after "played"
    void PlaySong();
private:
    vector<Song*> m_songCatalog; //Holds all songs in input file as songs
    vector<Playlist*> m_playlists; //Holds all songs in play list
    int curr_Playlist;
};


#endif
