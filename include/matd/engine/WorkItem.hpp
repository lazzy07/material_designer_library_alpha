#pragma once
#include "../core/Core.hpp"
#include "../types/Argument.hpp"
#include "Kernel.hpp"
#include "Queue.hpp"
#include <map>

namespace MATD {
	class WorkItem {
	public:
		WorkItem(Kernel* kernel);

		void SetArgument(size_t index, DTYPES::Argument* argument);
		inline const Kernel* GetKernel() const { return m_Kernel; };
		inline const std::map<size_t, DTYPES::Argument*>& GetArguments() const { return m_Arguments; };

		virtual void AddToQueue(MATD::Queue* queue) = 0;
		virtual void OnComplete() = 0;
		virtual void SetOutput(size_t index, DTYPES::Argument* argument) = 0;

		static WorkItem* CreateWorkItem(Kernel* kernel);
	private:
		Kernel* m_Kernel;
		std::map<size_t, DTYPES::Argument*> m_Arguments;
	};
}