#pragma once
#include "../../matd/Struct.hpp"
#include <cl/cl.hpp>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
      template<class T>
			class Struct : public MATD::Struct<T> {
			public:
				Struct(T val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;

			private:
				cl::Buffer m_CLBuffer;
			};
		}
	}
}