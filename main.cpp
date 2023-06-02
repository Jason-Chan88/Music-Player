#include <iostream>
#include "MusicPlayer.h" //Loads the MusicPlayer

int main (int argc, char* argv[]) {
    string musicFile;
    cout << "Welcome to UMBC Music Player"<<endl;
    if(argc > 1){
        musicFile = argv[1]; //stores the first argument as musicFile
    } else{
        cout << "One music files required - try again" << endl;
        cout << "./proj3 proj3_music.txt" << endl;
        //return 0;
    }
    MusicPlayer* myMusic = new MusicPlayer(); //Dynamically allocates a new music player
    myMusic->LoadCatalog(musicFile); //Loads the catalog
    myMusic->MainMenu(); //Calls MainMenu
    delete myMusic; //Deallocates the music player
    return 0;
}
