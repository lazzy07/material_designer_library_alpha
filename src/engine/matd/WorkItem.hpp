#pragma once
#include "../../core/Core.hpp"
#include "../../types/matd/Argument.hpp"
#include "Kernel.hpp"
#include <map>

namespace MATD {
	class WorkItem {
	public:
		virtual void AddToQueue() = 0;
		void SetArgument(DTYPES::Argument* argument);
		virtual void OnComplete() = 0;
		static WorkItem* CreateWorkItem(Kernel* kernel);
	private:
		std::map<size_t, DTYPES::Argument*> m_Arguments;
	};
	
}