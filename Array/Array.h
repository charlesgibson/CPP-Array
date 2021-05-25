#pragma once

#include "pch.h"

class IndexOutOfRangeException {

};

template<typename T>
class Array {
private:
	T* _elements{ nullptr };
	unsigned int _elementCount{ 0 };

public:
	Array() = default;
	explicit Array(const unsigned int elementCount) {
		_elementCount = elementCount;
		_elements = new T[elementCount];
	}

	~Array() {
		delete[] _elements;
	}

	unsigned int elementCount() const {
		return _elementCount;
	}

	T& operator[](const unsigned int index) const {
		if (indexIsOutOfRange(index)) {
			throw IndexOutOfRangeException{};
		}
		return _elements[index];
	}

private:
	bool indexIsOutOfRange(const unsigned int index) const {
		return index >= _elementCount;
	}
};