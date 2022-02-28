#pragma once
#include "Argument.hpp"
#include "MatdDataTypes.hpp"

namespace MATD {
	class MatColorVec3 : public DTYPES::Argument {
	public:
		MatColorVec3(MATD::ColorVec3 val);

		inline MATD::ColorVec3 GetVal() const { return m_Value; };
		inline void SetVal(MATD::ColorVec3 val) { m_Value = val; };

		virtual void Bind(WorkItem* workItem, size_t index) = 0;
		virtual void Delete() = 0;
		virtual void AddToQueue(MATD::Queue* queue) = 0;
	private:
		MATD::ColorVec3 m_Value;
	};
}