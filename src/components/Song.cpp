#include "Song.h"
#include <iostream>
#include <string>

using namespace std;

bool Song::Serialize(rapidjson::Writer<rapidjson::StringBuffer> * writer) const
{
  writer->StartObject();

        // write the Id value from the object instance

    writer->String("song_name");
    writer->String(_song_name.c_str());

    writer->String("danceability");
    writer->Double(_danceability);

    writer->String("energy");
    writer->Double(_energy);

    writer->String("key"); // create Id property
    writer->Int(_key); 

    writer->String("loudness");
    writer->Double(_loudness);

    writer->String("speechiness");
    writer->Double(_speechiness);

    writer->String("acousticness");
    writer->Double(_acousticness);

    writer->String("instrumentalness");
    writer->Double(_instrumentalness);

    writer->String("liveness");
    writer->Double(_liveness);

    writer->String("valence");
    writer->Double(_valence);

  writer->EndObject();

  return true;
}

bool Song::Deserialize(const rapidjson::Value & obj)
{
  Key(obj["key"].GetInt());
  Name(obj["song_name"].GetString());
  Danceability(stod(obj["danceability"].GetString()));
  Energy(stod(obj["energy"].GetString()));
  Loudness(stod(obj["loudness"].GetString()));
  Valence(stod(obj["valence"].GetString()));
  Speechiness(stod(obj["speechiness"].GetString()));
  Acousticness(stod(obj["acousticness"].GetString()));
  Liveness(stod(obj["liveness"].GetString()));
  Instrumentalness(stod(obj["instrumentalness"].GetString()));
 
  return true;
}

Song::~Song() {};


