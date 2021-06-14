#pragma once 

namespace MATD {
	namespace ENGINE {
		class Argument {
		public:
			inline const std::string& GetID() const { return m_ID; };
			inline void SetID(const std::string& ID) { m_ID = ID; };
		private:
			std::string m_ID;
		};
	}
}