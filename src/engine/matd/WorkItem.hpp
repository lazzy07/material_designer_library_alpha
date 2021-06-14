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
			void SetArgument(Argument* argument);
			virtual void OnComplete() = 0;
		private:
			std::map<std::string, ENGINE::Argument*> m_Arguments;
		};
	}
}