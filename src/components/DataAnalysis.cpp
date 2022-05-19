#include "DataAnalysis.h"
#include "Song.h"
#include <math.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

DataAnalysis::DataAnalysis(std::list<Song>& songList) {
    std::vector<Song> result(songList.begin(), songList.end());
    songs_ = result;
    getAverages();
}

void DataAnalysis::getAverages() {
    double averageKey = 0;
    double averageDanceability = 0;
    double averageEnergy = 0;
    double averageLoudness = 0;
    double averageValence = 0;
    double averageSpeechiness = 0;
    double averageAcousticness = 0;
    double averageLiveness = 0;
    double averageInstrumentalness = 0;

    for (auto it = songs_.begin(); it != songs_.end(); it++) {
        averageKey += (*it).Key();
        averageDanceability += (*it).Danceability();
        averageEnergy += (*it).Energy();
        averageLoudness += (*it).Loudness();
        averageValence += (*it).Valence();
        averageSpeechiness += (*it).Speechiness();
        averageAcousticness += (*it).Acousticness();
        averageLiveness += (*it).Liveness();
        averageInstrumentalness += (*it).Instrumentalness();

    }

    averageKey_ = averageKey / songs_.size();
    averageDanceability_ = averageDanceability / songs_.size();
    averageEnergy_ = averageEnergy / songs_.size();
    averageLoudness_ = averageLoudness / songs_.size();
    averageValence_ = averageValence / songs_.size();
    averageSpeechiness_ = averageSpeechiness / songs_.size();
    averageAcousticness_ = averageAcousticness / songs_.size();
    averageLiveness_ = averageLiveness / songs_.size();
    averageInstrumentalness_ = averageInstrumentalness / songs_.size();
}

double DataAnalysis::getScoreDifference(Song song) {
    double keyDifference = std::abs(averageKey_ - song.Key());
    double danceabilityDifference = std::abs(averageDanceability_ - song.Danceability());
    double energyDifference = std::abs(averageEnergy_ - song.Energy());
    double loudnessDifference = std::abs(averageLoudness_ - song.Loudness());
    double valenceDifference = std::abs(averageValence_ - song.Valence());
    double speechinessDifference = std::abs(averageSpeechiness_ - song.Speechiness());
    double acousticnessDifference = std::abs(averageAcousticness_ - song.Acousticness());
    double livenessDifference = std::abs(averageLiveness_ - song.Liveness());
    double instrumentalnessDifference = std::abs(averageInstrumentalness_ - song.Instrumentalness());

    double totalDifference = keyDifference + danceabilityDifference + energyDifference + loudnessDifference + valenceDifference + speechinessDifference
    + acousticnessDifference + livenessDifference + instrumentalnessDifference;

    averageScore_ = sqrt(totalDifference);
    return averageScore_;
}

double DataAnalysis::getScoreDifference(Song song1, Song song2) {
    double keyDifference = std::abs(song2.Key() - song1.Key());
    double danceabilityDifference = std::abs(song2.Danceability() - song1.Danceability());
    double energyDifference = std::abs(song2.Energy() - song1.Energy());
    double loudnessDifference = std::abs(song2.Loudness() - song1.Loudness());
    double valenceDifference = std::abs(song2.Valence() - song1.Valence());
    double speechinessDifference = std::abs(song2.Speechiness() - song1.Speechiness());
    double acousticnessDifference = std::abs(song2.Acousticness() - song1.Acousticness());
    double livenessDifference = std::abs(song2.Liveness() - song1.Liveness());
    double instrumentalnessDifference = std::abs(song2.Instrumentalness() - song1.Instrumentalness());

    double totalDifference = keyDifference + danceabilityDifference + energyDifference + loudnessDifference + valenceDifference + speechinessDifference
    + acousticnessDifference + livenessDifference + instrumentalnessDifference;

    averageScore_ = sqrt(totalDifference);
    return averageScore_;
}

double DataAnalysis::getAverageDifference() {
    double average = 0.0;
    for (unsigned int i = 0; i < songs_.size(); i++) {
        for (unsigned int j = i; j < songs_.size(); j++) {
            if (j == i) {
                continue;
            }

            average += getScoreDifference(songs_[i], songs_[j]);

        }
    }

    double denom = (songs_.size() * (songs_.size() - 1)) / 2;
    average = average / denom;
    return average ;
}

std::vector<Song> DataAnalysis::getSongs() {
    return songs_;
};
