#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <sstream>

#include "ResourceType.h"

namespace SoftUni {
	class Resource {
	private:
		int id = 0;
		ResourceType type;
		std::string link;
	public:
		bool operator<(const Resource& other) const {
			return id < other.id;
		}
		ResourceType getType(void) const { return type; }
		friend std::istream& operator>> (std::istream& istr, Resource& res);
		friend std::ostream& operator<< (std::ostream& ostr, const Resource& res);

	};

	std::istream& operator>> (std::istream& istr, Resource& res) {
		std::string strType;
		istr >> res.id >> strType >> res.link;
		if (strType == "Demo")
		{
			res.type = ResourceType::DEMO;
		}
		else if (strType == "Presentation")
		{
			res.type = ResourceType::PRESENTATION;
		}
		if (strType == "Video")
		{
			res.type = ResourceType::VIDEO;
		}
		return istr;
	}
	std::ostream& operator<< (std::ostream& ostr, const Resource& res) {
		ostr << res.id << " " << res.type << " " << res.link;
		return ostr;
	}


}


#endif // !RESOURCE_H
