#pragma once
#include "../../core/Core.hpp"
#include "../../types/matd/Argument.hpp"
#include "Kernel.hpp"
#include <map>

namespace MATD {
		class WorkItem {
		public:
			static Ref<WorkItem> CreateWorkItem(Ref<ENGINE::Kernel> kernel);
			virtual void AddToQueue() = 0;
			void SetArgument(DTYPES::Argument* argument);
			virtual void OnComplete() = 0;
		private:
			std::map<size_t, DTYPES::Argument*> m_Arguments;
		};
}