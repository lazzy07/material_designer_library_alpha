#pragma once
#include "Argument.hpp"

namespace MATD {
	namespace DTYPES {
		class Texture;
	}

	class Image : public DTYPES::Argument {
	public:
		Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType, DTYPES::Texture* texture = nullptr);

		void* GetImageData() { return m_Value; }
		[[nodiscard]] size_t GetSize() const { return m_Size; }
		[[nodiscard]] size_t GetByteSize() const { return m_ByteSize; }
		[[nodiscard]] size_t GetElementSize() const { return m_ElementSize; }
		[[nodiscard]] size_t GetWidth() const { return m_Width; }
		[[nodiscard]] size_t GetHeight() const { return m_Height; }

		[[nodiscard]] MATD::DTYPES::Texture* GetTexture() const { return m_Texture; };
		void SetTexture(MATD::DTYPES::Texture* texture) { m_Texture = texture; };

		virtual void Bind(WorkItem* workItem, size_t index) = 0;
		virtual void Delete() = 0;
		virtual void AddToQueue(MATD::Queue* queue) = 0;
	private:
		void* m_Value;
		buf_type m_BufType;
		size_t m_Size = 0;
		size_t m_ElementSize = 0;
		size_t m_ByteSize = 0;

		size_t m_Width = 0;
		size_t m_Height = 0;

		MATD::DTYPES::Texture* m_Texture;
	};
}