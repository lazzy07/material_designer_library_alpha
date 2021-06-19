#pragma once
#include "../../matd/WorkItem.hpp"
#include "CLKernel.hpp"
#include <CL/cl.hpp>
#include "../../../types/vendor/opencl/CLBuffer.hpp"
#include "../../../types/vendor/opencl/CLImage.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class WorkItem : public MATD::WorkItem {
			public:
				WorkItem(Kernel* kernel);
				virtual void AddToQueue() override;
				virtual void OnComplete() override;
				virtual void SetOutput(Buffer* buffer) override;
				virtual void SetOutput(Image* image) override;
			private:
				size_t m_OutputSize = 0;
				DTYPES::OPENCL::Buffer* m_OutBuffer;
				DTYPES::OPENCL::Image* m_OutImage;
			};
		}
	}
}