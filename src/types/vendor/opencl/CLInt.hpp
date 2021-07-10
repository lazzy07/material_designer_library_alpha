#pragma once
#include "../../matd/Int.hpp"
#include <cl/cl.hpp>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Int : public MATD::Int {
			public:
				Int(int val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;

			private:
				cl::Buffer m_CLBuffer;
			};
		}
	}
}