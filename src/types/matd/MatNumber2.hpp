#pragma once
#include "Argument.hpp"
#include "MatdDataTypes.hpp"

namespace MATD {
	class MatNumber2 : public DTYPES::Argument {
	public:
		MatNumber2(MATD::Number2 val);

		inline MATD::Number2 GetVal() const { return m_Value; };
		inline void SetVal(MATD::Number2 val) { m_Value = val; };

		virtual void Bind(WorkItem* workItem, size_t index) = 0;
		virtual void Delete() = 0;
		virtual void AddToQueue(MATD::Queue* queue) = 0;
	private:
		MATD::Number2 m_Value;
	};
}