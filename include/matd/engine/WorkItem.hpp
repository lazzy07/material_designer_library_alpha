#pragma once
#include "Kernel.hpp"
#include "../types/Argument.hpp"
#include <map>

namespace MATD {
	class WorkItem {
	public:
		WorkItem(Kernel* kernel);
		virtual void AddToQueue() = 0;
		virtual void OnComplete() = 0;
		void SetArgument(DTYPES::Argument* argument);
		inline const Kernel* GetKernel() const { return m_Kernel; };

		static WorkItem* CreateWorkItem(Kernel* kernel);
	private:
		Kernel* m_Kernel;
		std::map<size_t, DTYPES::Argument*> m_Arguments;
	};
	
}