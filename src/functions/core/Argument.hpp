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
			static MATD::DATA_TYPES StringToArgumentType(std::string str);

			Argument(std::string id, MATD::DATA_TYPES dataType, void* data);
			~Argument();

			inline const std::string& GetID() { return m_ID; };
			inline const MATD::DATA_TYPES GetDataType() { return m_DataType; };

			template <class T>
			inline T* GetData() { return (T*)m_Data; };

			template <class T>
			inline void SetData(T data) { memcpy(m_Data, &data, sizeof(T)); };

			/**
			 * @param dataType Data type
			 * @param data Data needs to be stored
			 * This function will assign data using json information 
						{
							"id": "111",
							"name": "Default Value",
							"data": 1,
							"dataType": "number",
							"groups": {
								"id": "1111",
								"name": "Default"
							},
							"inputType": "input",
							"type": ""
						}
			 */
			void SetData(MATD::JSON JSONObj);

		private:
			std::string m_ID;
			MATD::DATA_TYPES m_DataType;
			void* m_Data;
		};
	}
}