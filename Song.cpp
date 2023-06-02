#include "Song.h"

Song::Song() {
    m_title = "New Title";
    m_artist = "New Artist";
    m_year = 0;
    m_rank = 0;
    m_next = nullptr;
}

Song::Song(string title, string artist, int year, int rank) {
    SetTitle(title);
    SetArtist(artist);
    SetYear(year);
    SetRank(rank);
    m_next = nullptr;
}

string Song::GetTitle() {
    return m_title;
}

string Song::GetArtist() {
    return m_artist;
}

int Song::GetYear() {
    return m_year;
}

int Song::GetRank() {
    return m_rank;
}

void Song::SetTitle(string title) {
    m_title = title;
}

void Song::SetArtist(string artist) {
    m_artist = artist;
}

void Song::SetYear(int year) {
    m_year = year;
}

void Song::SetRank(int rank) {
    m_rank = rank;
}

Song* Song::GetNext() {
    return m_next;
}

void Song::SetNext(Song* newSong) {
       m_next = newSong;
}