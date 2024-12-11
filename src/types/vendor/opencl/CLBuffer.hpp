#pragma once
#include "../../matd/Buffer.hpp"
#include <cl/cl.hpp>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			/**
			 * @brief OpenCL Buffer class that inherits from MATD::Buffer, this class is used to store the buffer data and bind it to the kernel arguments 
			 * to be used in the OpenCL kernel and to be added to the OpenCL queue
			 * 
			 */
			class Buffer : public MATD::Buffer {
			public:
				Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType);
				inline cl::Buffer GetCLBuffer() const { return m_CLBuffer; };

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			private:
				cl::Buffer m_CLBuffer;
			};
		}
	}
}