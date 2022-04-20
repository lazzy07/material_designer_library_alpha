#pragma once
#include "../../core/Core.hpp"
#include "../../types/matd/Argument.hpp"
#include "Kernel.hpp"
#include "Queue.hpp"
#include <map>

namespace MATD {
	class WorkItem {
	public:
		WorkItem(Kernel* kernel);

		void SetArgument(size_t index, DTYPES::Argument* argument);

		const Kernel* GetKernel() const { return m_Kernel; }
		const std::map<size_t, DTYPES::Argument*>& GetArguments() const { return m_Arguments; }

		virtual void AddToQueue(MATD::Queue* queue) = 0;
		virtual void OnComplete() = 0;

		virtual void SetOutput(Buffer* buffer) = 0;
		virtual void SetOutput(GrayscaleTexture* texture) = 0;
		virtual void SetOutput(ColorTexture* texture) = 0;

		static WorkItem* CreateWorkItem(Kernel* kernel);
	private:
		Kernel* m_Kernel;
		std::map<size_t, DTYPES::Argument*> m_Arguments;
	};
}