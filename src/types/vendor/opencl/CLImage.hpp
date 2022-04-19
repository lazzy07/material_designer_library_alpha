#pragma once
#include "../../matd/Image.hpp"
#include "../../../types/matd/Texture.hpp"
#include <cl/cl.hpp>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Image : public MATD::Image {
			public:
				static int NoOfChannelsToCLChannelTypes(size_t noOfChannels);
				static int BitTypeToCLBitType(MATD::MATD_TEXTURE_BIT_TYPE bitType);
				Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			private:
				cl::Image2D m_CLImage2D;
			};
		}
	}
}