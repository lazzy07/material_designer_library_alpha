#pragma once
#include "Argument.hpp"

namespace MATD {
	namespace DTYPES {
		class Int : public Argument {
		public:
			Int(int val);

			inline int GetVal() const { return m_Value; };
			inline void SetVal(int val) { m_Value = val; };
		private:
			int m_Value = 0;
		};
	}
}