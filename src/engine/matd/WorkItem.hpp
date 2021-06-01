#pragma once
#include "Program.hpp"
#include "../../core/Core.hpp"

namespace MATD {
	namespace ENGINE {
		class WorkItem {
		public:
			static Ref<WorkItem> CreateWorkItem();
			virtual void AddToQueue() = 0;
			virtual void SetArgument() = 0;
			void SetProgram(Program program) { m_Program = program; };
			virtual void OnComplete() = 0;
		private:
			Program m_Program;
		};
	}
}