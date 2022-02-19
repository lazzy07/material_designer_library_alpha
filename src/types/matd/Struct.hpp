#pragma once
#include "Argument.hpp"

namespace MATD {
		template<class T>
		class Struct : public DTYPES::Argument {
		public:
			Struct(T val);

			inline const T& GetValRef() const { return m_Value; };
			inline T GetVal() const { return m_Value; };

			inline void SetVal(T val) { m_Value = val; };

			virtual void Bind(WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
		private:
			T m_Value;
		};
}