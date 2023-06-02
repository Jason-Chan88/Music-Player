#include "Playlist.h"

Playlist::Playlist() {

    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

}

Playlist::~Playlist() {

    Song *temp = m_head->GetNext();
    while (temp != nullptr) {
        delete m_head;
        m_head = temp;
        temp = temp->GetNext();
    }
    delete m_head;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

}

void Playlist::AddSong(string title, string artist, int year, int rank) {

    Song* temp = new Song (title, artist,year, rank);

    m_tail->SetNext(temp);
    m_tail = temp;
    m_size++;
}

Song* Playlist::GetPlaylistDetails(int location) {

    int i = 1;
    Song *temp = m_head;

    if (location < m_size) {
        while (i < location) {
            temp = temp->GetNext();
            i++;
        }
        return temp;
    }
    else{
        return nullptr;
    }
}

int Playlist::Size() {
    return m_size;
}

void Playlist::PlayAt(int location) {
    Song* prev = m_head;
    Song* curr = m_head;
    int i = 0;
    while (i != location){
        prev = curr;
        curr = curr->GetNext();
        i++;
    }

    cout << "Played: " << '"' << curr->GetTitle() << " by " << curr->GetArtist() << i << "/" << m_size << endl;

    if (m_size == 1) {
        m_head = nullptr;
        m_tail = nullptr;
        delete curr;
        delete prev;
    }
    else if(location == m_size){
        m_tail = prev;
        delete curr;
        prev->SetNext(nullptr);
    }
    else{
        Song* temp = curr->GetNext();

        delete curr;

        curr = prev;
        curr->SetNext(temp);

        if (location == 0){
            m_head = temp;
        }

    }

    m_size--;
}
//returns m_name
string Playlist::GetName(){
    return m_name;
}
// set m_name to name
void Playlist::SetName(string name){
    m_name = name;
}



