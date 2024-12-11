#pragma once
#include "../../matd/MatColorVec3.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			/**
			 * @brief OpenCL ColorVec3 class that inherits from MATD::MatColorVec3, this class is used to store the color vector data and bind it to the kernel arguments 
			 * to be used in the OpenCL kernel and to be added to the OpenCL queue
			 * 
			 */
			class ColorVec3 : public MATD::MatColorVec3 {
			public:
				ColorVec3(MATD::ColorVec3 val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			};
		}
	}
}