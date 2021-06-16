#pragma once
#include "Kernel.hpp"
#include "../types/Argument.hpp"
#include <map>

namespace MATD {
	namespace ENGINE {
		class WorkItem {
		public:
			static Ref<WorkItem> CreateWorkItem(Ref<Kernel> kernel);
			virtual void AddToQueue() = 0;
			void SetArgument(MATD::DTYPES::Argument* argument);
			virtual void OnComplete() = 0;
		};
	}
}