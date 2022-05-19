#include "Songs.h"
#include <iostream>

using namespace std;


// TODO: documentation

	bool Songs::Deserialize(const std::string& s)
	{
		rapidjson::Document doc;
		if (!InitDocument(s, doc))
			return false;

		if (!doc.IsArray())
			return false;

		int i = 0;
		for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End(); ++itr)
		{
			if (i >= 10) { // controls number of songs to deserialize
				break;
			}

			Song s;
			s.Deserialize(*itr);
			if (s.Name() != "") {
				s.Index(i);
				_songs.push_back(s);
				i++;
			}
		}

		return true;
	}

	bool Songs::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
	{
		writer->StartArray();

		for (std::list<Song>::const_iterator it = _songs.begin(); it != _songs.end(); it++)
		{
			(*it).Serialize(writer);
		}
		writer->EndArray();

		return true;
	}

	bool Songs::Deserialize(const rapidjson::Value& obj) { 
		if (obj != NULL) {
			return false;
		}
		return false; };

