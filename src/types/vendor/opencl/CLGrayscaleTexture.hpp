#pragma once

#include "../../matd/Argument.hpp"
#include "../../matd/GrayscaleTexture.hpp"
#include <cl/cl.hpp>

namespace MATD::DTYPES::OPENCL
{
   class GrayscaleTexture : public MATD::GrayscaleTexture
   {
   public:
     GrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType);

     [[nodiscard]] cl::Image2D GetCLImage() const { return m_CLImage2D; }

     void Bind(WorkItem* workItem, size_t index) override;
     void Delete() override;
     void AddToQueue(MATD::Queue* queue) override;
   private:
     cl::Image2D m_CLImage2D;
   };
}
