#pragma once
#include "../../matd/WorkItem.hpp"
#include "CLKernel.hpp"
#include "../../matd/Queue.hpp"
#include "../../../types/vendor/opencl/CLBuffer.hpp"
#include "../../../types/vendor/opencl/CLGrayscaleTexture.hpp"
#include "../../../types/vendor/opencl/CLColorTexture.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class WorkItem : public MATD::WorkItem {
			public:
				WorkItem(Kernel* kernel);
				virtual void AddToQueue(MATD::Queue* queue) override;
				virtual void OnComplete() override;
				virtual void SetOutput(Buffer* buffer) override;
				virtual void SetOutput(DTYPES::Texture* texture) override;
			private:
				size_t m_OutputSize = 0;
				DTYPES::OPENCL::Buffer* m_OutBuffer;
				DTYPES::OPENCL::ColorTexture* m_OutColorTexture;
				DTYPES::OPENCL::GrayscaleTexture* m_OutGrayscaleTexture;
			};
		}
	}
}