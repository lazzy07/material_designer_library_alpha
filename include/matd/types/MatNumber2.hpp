#pragma once
#include "Argument.hpp"


//This is the data type that is created to pass into OpenCL or CUDA, as this has all the functionality required to bind this into those vendors, do not get mixed up with Number2 struct which is the generic structure used for data transfer within the application.
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