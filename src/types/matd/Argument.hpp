#pragma once 
#include <string>


namespace MATD {
	namespace ENGINE {
		class WorkItem;
	}

	namespace DTYPES {
		class Argument {
		public:
			inline const size_t& GetID() const { return m_ID; };
			inline void SetID(const size_t& ID) { m_ID = ID; };

			virtual void Bind(const ENGINE::WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
		private:
			size_t m_ID;
		};
	}
}