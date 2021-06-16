#pragma once
#include "Kernel.hpp"
#include "../types/Argument.hpp"
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