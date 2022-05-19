
#pragma once

#include "../JSONBase.h"
#include <list>
#include <string>

class Song : public JSONBase
{
public:
  virtual ~Song();			

  virtual bool Deserialize(const rapidjson::Value& obj);
  virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

  // Getters/Setters.
  const std::string& Name() const { return _song_name; }
  void Name(const std::string& name) { _song_name = name; }

  double Danceability() const { return _danceability; }
  void Danceability(double danceability) { _danceability = danceability; }

  double Energy() const { return _energy; }
  void Energy(double energy) { _energy = energy; }

  double Key() const { return _key; }
  void Key(double key) { _key = key; }

  double Valence() const {return _valence;}
  void Valence(double valence){ _valence = valence;}

  double Loudness() const { return _loudness; }
  void Loudness(double loudness) { _loudness = loudness; }

  double Liveness() const {return _liveness;}
  void Liveness(double liveness) {_liveness = liveness;}

  double Speechiness() const { return _speechiness; }
  void Speechiness(double speechiness) { _speechiness = speechiness; }

  double Instrumentalness() const {return _instrumentalness;}
  void Instrumentalness(double instrumentalness) {_instrumentalness = instrumentalness;}

  double Acousticness() const { return _acousticness; }
  void Acousticness(double acousticness) { _acousticness = acousticness; }

  double Index() const { return _index;}
  void Index(int ind) {_index = ind;}

	
private:
  std::string _song_name;
  double _danceability;
  double _energy;
  int _key;
  double _loudness;
  double _speechiness;
  double _acousticness;
  double _instrumentalness;
  double _liveness;
  double _valence;
  int _index;
};
