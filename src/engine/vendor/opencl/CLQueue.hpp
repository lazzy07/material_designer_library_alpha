#pragma once
#include <cl/cl.hpp>
#include "../../matd/Queue.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class Queue : public MATD::Queue {
			public:
				Queue();
				~Queue();
				inline const cl::CommandQueue& GetCLQueue() const { return m_Queue; };
			private:
				cl::CommandQueue m_Queue;
			};
		}
	}
}