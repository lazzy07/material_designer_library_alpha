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
		inline const std::map<size_t, DTYPES::Argument*>& GetArguments() const { return m_Arguments; };
		inline const bool GetHasCalledExecute() const { return m_HasCalledExecute; };
		inline void SetHasCalledExecute(bool hasCalledExecute) { m_HasCalledExecute = hasCalledExecute; };

		void SetEnqueueStatus(size_t index, bool status);


		virtual void AddToQueue() = 0;
		virtual void OnComplete() = 0;
		virtual void SetOutput(Buffer* buffer) = 0;
		virtual void SetOutput(Image* image) = 0;


		static WorkItem* CreateWorkItem(Kernel* kernel);
	private:
		bool m_HasCalledExecute = false;
		Kernel* m_Kernel;
		std::map<size_t, DTYPES::Argument*> m_Arguments;
		std::map<size_t, bool> m_EnqueueStatus;
	};
}