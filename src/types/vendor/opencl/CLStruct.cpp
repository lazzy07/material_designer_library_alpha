#include "CLStruct.hpp"

template<class T>
inline MATD::DTYPES::OPENCL::Struct<T>::Struct(T val) : MATD::Struct(MAT_ARG::MAT_STRUCT), m_Value(val)
{
	MATD_CORE_TRACE("CL_STRUCT:::Created CL Struct val:{}", val);
}

template<class T>
void MATD::DTYPES::OPENCL::Struct<T>::Bind(WorkItem* workItem, size_t index)
{
	const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
	cl::Kernel clKernel = kernel->GetCLKernel();
	clKernel.setArg<T>(index, GetVal());
	MATD_CORE_TRACE("CL_Struct::Strcut value bound to kernel:{} at index:{}", kernel->GetID(), index);
}

template<class T>
void MATD::DTYPES::OPENCL::Struct<T>::Delete()
{
}

template<class T>
void MATD::DTYPES::OPENCL::Struct<T>::AddToQueue(MATD::Queue* queue)
{
}