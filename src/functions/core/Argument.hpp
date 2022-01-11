#pragma once
#include <string>
#include "../../types/matd/MatdDataTypes.hpp"
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"

namespace MATD {
	namespace FUNC {
		class Argument {
		public:
			static MATD::Ref<Argument> ArgumentFactory(MATD::JSON JSONObj);

			Argument(std::string id, MATD::DATA_TYPES dataType, void* data);
			~Argument();

			inline const std::string& GetID() { return m_ID; };
			inline const MATD::DATA_TYPES GetDataType() { return m_DataType; };
			template<class T>
			inline T* GetData() { return (T*)m_Data; };

		private:
			std::string m_ID;
			MATD::DATA_TYPES m_DataType;
			void* m_Data;
		};
	}
}