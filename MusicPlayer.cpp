#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
    curr_Playlist = 0;
}
// Destructor for MusicPlayer
MusicPlayer::~MusicPlayer() {
    // Runs through m_songCatalog and deletes every song in that catalog
    for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
        delete m_songCatalog.at(i);
    }
    //Runs through m_playlists and deletes every playlist in playlist
    for (unsigned int i = 0; i < m_playlists.size(); i++) {
        delete m_playlists.at(i);
    }
}
// This function for putting songs into m_songCatalog
void MusicPlayer::LoadCatalog(string filename) {

    ifstream myfile; // for the file
    string title = "";
    string artist = "";
    string year = "";
    string rank = "";
    // the files open than it puts all songs inside your song catalog
    myfile.open(FILE_NAME);
    if (myfile.is_open()) {
        while (getline(myfile, title,DELIMITER)) {
            // using delimiter to seperate yours songs and put them into their variable
            (getline(myfile, artist, DELIMITER));
            (getline(myfile, year, DELIMITER));
            (getline(myfile, rank));
            // puts new songs into temp with the song variable from the file and puts it at the end of m_songCatalog
            Song* temp = new Song (string (title), string (artist), stoi(string(year)),stoi(string(rank)));
            m_songCatalog.push_back(temp);

        }
        // tell you how many songs you have and it should be 1200
        cout << "Songs loaded: " << m_songCatalog.size() << endl;
        myfile.close();
    }
    else {
        cout << "your file doesn't open, try another" << endl;
    }
}

void MusicPlayer::MainMenu() {
    int decision = 0; // needs this for your decision
    // keeps the while loop running until you quit the program via 7
    while (decision != 7) {
        cout << "What do you like to do?" << endl;
        cout << "1. Create New Playlist" << endl;
        cout << "2. Choose Playlist to Edit" << endl;
        cout << "3. Display songs by Year" << endl;
        cout << "4. Add Song to Current Playlist" << endl;
        cout << "5. Display Current Playlist" << endl;
        cout << "6. Play Song" << endl;
        cout << "7. Quit" << endl;
        cin >> decision;

        // depending on your decision it goes to 6 different function
        if (decision == 1) {
            CreateNewPlaylist();
        }
        else if (decision == 2) {
            ChoosePlaylist();
        }
        else if (decision == 3) {
            DisplaySongs();
        }
        else if (decision == 4) {
            AddSong();
        }
        else if (decision == 5) {
            DisplayPlaylist();
        }
        else if (decision == 6) {
            PlaySong();
        }
    }
    cout << "Thank you for using the UMBC Music Player" << endl;
}
//Creates new playlist
void MusicPlayer::CreateNewPlaylist(){
    string name;

    //takes in any characters for string name
    cout << "Enter name for playlist?" <<  endl;
    cin >> name;

    //create new playlist object and set name of playlist
    Playlist* temp = new Playlist();
    temp->SetName(name);

    //insert new playlist into end of m_playlists vector
    m_playlists.push_back(temp);

    //sets curr_Playlist to index of new playlist created (which is the end of the m_playlist vector)
    curr_Playlist = m_playlists.size() - 1;
    cout << "Your current playlist is: " << m_playlists[curr_Playlist]->GetName() << endl;

}

void MusicPlayer::ChoosePlaylist(){
    int choice = 0;


    if (m_playlists.size() == 0) {
        cout << "No Playlist, create one" << endl;
    }

    else {

        cout << "Playlist options:" << endl;
        // prints out all your playlist
        for(unsigned int i = 0; i < m_playlists.size(); i++) {
            cout << i+1 << ". " << m_playlists.at(i)->GetName() << endl;
        }
        // make sure your choice is within bounds
        while (choice < 1 || choice > (int)m_playlists.size()) {
            cout << "Choose Playlist, enter a number" << endl;
            cin >> choice;
        }
        // sets curr_Playlist to index of player choice
        curr_Playlist = choice - 1;
        cout << "Your current playlist is " << m_playlists[curr_Playlist]->GetName() << endl;

    }
}
// Displays all the songs in a specific year
void MusicPlayer::DisplaySongs() {
    int songYear = 0;
    // makes sure the year are between 2010-2021
    while (songYear < LOW_YEAR || songYear > HIGH_YEAR) {
        cout << "Which year would you like to display? (2010-2021)" << endl;
        cin >> songYear;
    }
    // Runs through all the songs in that year with a for loop
    cout << "******"<< songYear << "*******" << endl;
    for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
        // for printing out the songs of just the year you choose
        if (m_songCatalog[i]->GetYear() == songYear) {
            // the * access the friend operator that already has the cout statement for songs
            cout << i+1 << ". " <<*m_songCatalog.at(i) << endl;
        }
    }
}

void MusicPlayer::AddSong() {

    int songNum = 0;
    if (m_playlists.size() == 0) {
        cout << "you don't have a playlist" << endl;
    }
    else {

        if (m_playlists[curr_Playlist]->Size() == 0) {
            cout << "*** "<<m_playlists[curr_Playlist]->GetName() << " is Empty***" << endl;
        }

        cout << "Choose the songs you would like to add to the playlist." << endl;
        // displays all the song from that year by calling function
        DisplaySongs();
        // makes sure you choose a song between 1 and 1200
        while (songNum < 1 || songNum > (int)m_songCatalog.size()) {
            cout << "Enter the number of the song you would like to add:" << endl;
            cin >> songNum;
        }
        // variables for AddSong in playlist.cpp, use songnum to find the song in catalog and use getter to get the info
        string title = m_songCatalog[songNum-1]->GetTitle();
        string song = m_songCatalog[songNum-1]->GetArtist();
        int year = m_songCatalog[songNum-1]->GetYear();
        int rank = m_songCatalog[songNum-1]->GetRank();
        m_playlists[curr_Playlist]->AddSong(title,song, year, rank);
    }
}
// Displays all the songs in your playlist and uses * to use freind operator again
void MusicPlayer::DisplayPlaylist() {
    // checks if there are any playlists
    if (m_playlists.size() == 0) {
        cout << "you don't have a playlist" << endl;
    }
    else {
        // check current playlist size to see if it's empty
        if (m_playlists[curr_Playlist]->Size() == 0) {
            cout << m_playlists[curr_Playlist]->GetName() <<" is currently empty" << endl;
        }
        else{
            cout << m_playlists[curr_Playlist]->GetName() << endl;
            for (int i = 0; i < m_playlists[curr_Playlist]->Size(); i++) {
                // use GetPlaylistDetails in playlist to get the info we need to display the song in playlist
                cout << i+1 << ". " << *m_playlists[curr_Playlist]->GetPlaylistDetails(i)<< endl;
            }
        }
    }
}


void MusicPlayer::PlaySong() {

    int location = 0;
    if (m_playlists.size() == 0) {
        cout << "you don't have a playlist" << endl;
    }
    else {
        DisplayPlaylist();

        if (m_playlists[curr_Playlist]->Size() > 0) {
            // makes sure the song exist in current playlist
            while (location < 1 || location > m_playlists[curr_Playlist]->Size()) {
                cout << "Which song would you like to play?" << endl;
                cin >> location;
            }
            // prints out what you played via GetPlaylistDetails than runs AddSong in playlist to delete that song
            cout << "Played: " << *m_playlists[curr_Playlist]->GetPlaylistDetails(location-1) << endl;
            m_playlists[curr_Playlist]->PlayAt(location-1);

        }
    }
}

