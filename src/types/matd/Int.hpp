#pragma once
#include "Argument.hpp"

namespace MATD {
		class Int : public DTYPES::Argument {
		public:
			Int(size_t id, int val);

			inline int GetVal() const { return m_Value; };
			inline void SetVal(int val) { m_Value = val; };

			virtual void Bind(const WorkItem* workItem) = 0;
			virtual void Delete() = 0;
		private:
			int m_Value = 0;
		};
}