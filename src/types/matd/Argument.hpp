#pragma once 
#include <string>


namespace MATD {
	namespace ENGINE {
		class WorkItem;
	}

	namespace DTYPES {
		class Argument {
		public:
			inline const std::string& GetID() const { return m_ID; };
			inline void SetID(const std::string& ID) { m_ID = ID; };

			virtual void Bind(const ENGINE::WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
		private:
			std::string m_ID;
		};
	}
}