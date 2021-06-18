#pragma once
#include "Argument.hpp"

namespace MATD {
	class Image : public DTYPES::Argument {
	public:
		Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType = ARG_TYPE::DEVICE_READ | ARG_TYPE::HOST_WRITE);

		inline void* GetImageData() { return m_Value; };
		inline const size_t GetSize() const { return m_Size; };
		inline const size_t GetByteSize() const { return m_ByteSize; };
		inline const size_t GetElementSize() const { return m_ElementSize; };

		virtual void Bind(const WorkItem* workItem, size_t index) = 0;
		virtual void Delete() = 0;
	private:
		void* m_Value;
		buf_type m_BufType;
		size_t m_Size = 0;
		size_t m_ElementSize = 0;
		size_t m_ByteSize = 0;

		size_t m_Width = 0;
		size_t m_Height = 0;
	};
}