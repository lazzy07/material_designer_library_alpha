#pragma once
#include "Argument.hpp"

namespace MATD {
	namespace DTYPES {
			class Float : public Argument {
			public:
				Float(float val);

				inline float GetVal() const { return m_Value; };
				inline void SetVal(float val) { m_Value = val; };

			private:
				float m_Value  = 0.0f;
			};
	}
}