#pragma once

namespace MATD {
	class Int;
	class Float;
		
	template<typename T>
	class Buffer;

	template<typename T>
	class Image;

	class WorkItem;

	class Argument {
		public:
		static Int* Int(size_t id, int val);
		static Float* Float(size_t id, float val);

		template<typename T>
		static Buffer<T>* Buffer(size_t id, T* val, size_t size);

		template<typename T>
		static Image<T>* Image(size_t id, T* val, size_t size, size_t width, size_t height);
	};

	namespace DTYPES {
		class Argument {
		public:
			Argument(size_t id);
			inline const size_t& GetID() const { return m_ID; };
			inline void SetID(const size_t& ID) { m_ID = ID; };

			void Bind(const WorkItem* workItem);
			void Delete();
		private:
			size_t m_ID;
		};
	}
}