#pragma once

#include "../../matd/Argument.hpp"
#include "../../matd/ColorTexture.hpp"
#include <cl/cl.hpp>

namespace MATD::DTYPES::OPENCL
{
  /**
   * @brief OpenCL ColorTexture class that inherits from MATD::ColorTexture, this class is used to store the color texture data and bind it to the kernel arguments 
   * to be used in the OpenCL kernel and to be added to the OpenCL queue
   * 
   */
  class ColorTexture : public MATD::ColorTexture
  {
  public:
    ColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType);

    [[nodiscard]] cl::Image2D GetCLImage() const { return m_CLImage2D; }

    void Bind(WorkItem* workItem, size_t index) override;
    void Delete() override;
    void AddToQueue(MATD::Queue* queue) override;

  private:
    cl::Image2D m_CLImage2D;
  };
}
