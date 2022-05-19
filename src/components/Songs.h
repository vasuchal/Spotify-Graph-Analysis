#pragma once

#include "Song.h"
#include <list>

class Songs : public JSONBase
{
public:
  virtual bool Deserialize(const rapidjson::Value& obj);
  virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
  virtual bool Deserialize(const std::string& s);	
  std::list<Song>& SongsList() { return _songs; }
	


private:
	std::list<Song> _songs;

};
