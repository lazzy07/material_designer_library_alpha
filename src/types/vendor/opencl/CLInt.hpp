#pragma once
#include "../../matd/Int.hpp"
#include <cl/cl.hpp>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Int : public MATD::Int {
			public:
				Int(size_t id,int val);

				virtual void Bind(const WorkItem* workItem) override;
				virtual void Delete() override;
			private:
				cl::Buffer m_CLBuffer;
			};
		}
	}
}