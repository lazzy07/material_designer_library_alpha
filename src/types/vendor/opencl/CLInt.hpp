#pragma once
#include "../../matd/Int.hpp"
#include <cl/cl.hpp>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			/**
			 * @brief OpenCL Int class that inherits from MATD::Int, this class is used to store the int data and bind it to the kernel arguments 
			 * to be used in the OpenCL kernel and to be added to the OpenCL queue
			 * 
			 */
			class Int : public MATD::Int {
			public:
				Int(int val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;

			private:
				cl::Buffer m_CLBuffer;
			};
		}
	}
}