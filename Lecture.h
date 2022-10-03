#ifndef LECTURE_H
#define LECTURE_H


namespace SoftUni {
	class Lecture {
	private:
		std::set<Resource> resSet;
		std::map< ResourceType, size_t> countTypes;

	public:
		typedef std::set<Resource> typeDefSet;
		Lecture& operator<< (const Resource& res) {

			typeDefSet::iterator isExisting = resSet.find(res);

			if (isExisting != resSet.end())
			{
				countTypes[res.getType()]--;
				if (countTypes[res.getType()] == 0) {
					countTypes.erase(res.getType());
				}
				resSet.erase(res);
			}
			resSet.insert(res);
			countTypes[res.getType()]++;
			return *this;
		}

		int operator[] (ResourceType rType) const {
			std::map< ResourceType, size_t>::const_iterator itRT = countTypes.find(rType);
			if (itRT == countTypes.end())
			{
				return 0;
			}
			else
			{
				return itRT->second;
			}
		}

		typeDefSet::iterator begin(void) { return resSet.cbegin(); }
		typeDefSet::iterator end(void) { return resSet.cend(); }

		const std::map< ResourceType, size_t> getType(void) const { return countTypes; }


	};
	void  operator<< (std::vector< ResourceType>& vec, Lecture& lec) {

		for (auto r : lec.getType())
		{

			vec.push_back(r.first);
		}
	}

};
#endif

