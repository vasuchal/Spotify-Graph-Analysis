#include "Song.h"
#include <vector>
#include <list>

using namespace std;

class DataAnalysis {
    public:
        DataAnalysis(std::list<Song>& songList);

        /* Returns score difference from the calculated averages for each category of the song */
        double getScoreDifference(Song song);

        /* Returns score difference between two songs  */
        double getScoreDifference(Song song1, Song song2);

         /* Returns the calculated average difference between two songs  */
        double getAverageDifference();
        std::vector<Song> getSongs();

    private:
        std::vector<Song> songs_;
        double averageKey_;
        double averageDanceability_;
        double averageEnergy_;
        double averageLoudness_;
        double averageValence_;
        double averageSpeechiness_;
        double averageAcousticness_;
        double averageLiveness_;
        double averageInstrumentalness_;

        double averageScore_;

        /* Helper function used to calculate the averages for each category */
        void getAverages();
};
