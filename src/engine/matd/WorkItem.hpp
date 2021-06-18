#pragma once
#include "../../core/Core.hpp"
#include "../../types/matd/Argument.hpp"
#include "Kernel.hpp"
#include <map>

namespace MATD {
	class WorkItem {
	public:
		WorkItem(Kernel* kernel);
		void SetArgument(size_t index, DTYPES::Argument* argument);
		inline const Kernel* GetKernel() const { return m_Kernel; };

		virtual void AddToQueue() = 0;
		virtual void OnComplete() = 0;
		virtual void SetOutput(Buffer* buffer) = 0;
		virtual void SetOutput(Image* image) = 0;

		static WorkItem* CreateWorkItem(Kernel* kernel);
	private:
		Kernel* m_Kernel;
		std::map<size_t, DTYPES::Argument*> m_Arguments;
	};
	
}