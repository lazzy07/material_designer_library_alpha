#pragma once
#include "../../matd/Float.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			/**
			 * @brief OpenCL Float class that inherits from MATD::Float, this class is used to store the float data and bind it to the kernel arguments 
			 * to be used in the OpenCL kernel and to be added to the OpenCL queue
			 * 
			 */
			class Float : public MATD::Float {
			public:
				Float(float val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			};
		}
	}
}