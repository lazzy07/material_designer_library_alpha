#pragma once
#include "../../matd/MatNumber2.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			/**
			 * @brief OpenCL Number2 class that inherits from MATD::MatNumber2, this class is used to store the number2 data and bind it to the kernel arguments 
			 * to be used in the OpenCL kernel and to be added to the OpenCL queue
			 * 
			 */
			class Number2 : public MATD::MatNumber2 {
			public:
				Number2(MATD::Number2 val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			};
		}
	}
}