#pragma once
#include "../../core/Core.hpp"
#include "../../types/matd/Argument.hpp"
#include "Kernel.hpp"
#include <map>

namespace MATD {
	namespace ENGINE {
		class WorkItem {
		public:
			static Ref<WorkItem> CreateWorkItem(Ref<Kernel> kernel);
			virtual void AddToQueue() = 0;
			void SetArgument(DTYPES::Argument* argument);
			virtual void OnComplete() = 0;
		private:
			std::map<size_t, DTYPES::Argument*> m_Arguments;
		};
	}
}