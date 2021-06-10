#pragma once
#include "../../core/Core.hpp"
#include "Argument.hpp"

namespace MATD {
	namespace ENGINE {
		class WorkItem {
		public:
			static Ref<WorkItem> CreateWorkItem();
			virtual void AddToQueue() = 0;
			virtual void SetArgument(Argument argument) = 0;
			virtual void OnComplete() = 0;
		};
	}
}