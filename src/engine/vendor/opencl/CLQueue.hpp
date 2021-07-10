#pragma once
#include <cl/cl.hpp>
#include "../../matd/Queue.hpp"
#include <vector>

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class Queue : public MATD::Queue {
			public:
				Queue();
				~Queue();

				inline const cl::CommandQueue& GetCLQueue() const { return m_Queue; };
				inline const std::vector<cl::Event>& GetCLEvents() const { return m_Events; };
				inline void SetEvent(cl::Event event) { m_Events.push_back(event); };
			private:
				cl::CommandQueue m_Queue;
				std::vector<cl::Event> m_Events;
			};
		}
	}
}