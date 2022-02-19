#include "Struct.hpp"

template<class T>
inline MATD::Struct<T>::Struct(T val) : Argument(MAT_ARG::MAT_STRUCT), m_Value(val)
{
}