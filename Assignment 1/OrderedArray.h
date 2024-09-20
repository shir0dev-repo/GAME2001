#pragma once

#include "Array.h"

template <typename T>
class OrderedArray : public Array<T> {
public:
	inline OrderedArray(bool allowDuplicates, int size, int growBy = 1) : Array<T>(size, growBy) {
		m_allowDuplicates = allowDuplicates;
	}

	inline virtual void push(T value) override {
		NULLCHECK(this->m_array);

		const int duplicateIndex = find(value);
		int i, k;

		if (duplicateIndex != -1) {
			if (!m_allowDuplicates) {
				std::cout << "Duplicate data prevented." << std::endl;
				return;
			}
			else {
				if (this->m_numElements >= this->m_maxSize)
					this->expand();

				i = duplicateIndex;
			}
		}
		else {
			for (i = 0; i < this->m_numElements; i++) {
				if (this->m_array[i] > value) break;
			}
		}

		for (k = this->m_numElements; k > i; k--) {
			this->m_array[k] = this->m_array[k - 1];
		}

		this->m_array[i] = value;
		this->m_numElements++;
	}

	inline virtual void pop() override {

	}

	inline virtual int find(T searchKey) const override {
		NULLCHECK(this->m_array);

		int lowerBound = 0, upperBound = this->m_numElements - 1, current = 0;

		while (1) {
			current = (lowerBound + upperBound) >> 1;

			if (this->m_array[current] == searchKey) {
				return current;
			}
			else if (lowerBound > upperBound) {
				return -1;
			}
			else {
				if (this->m_array[current] < searchKey) {
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}
	}

private:
	bool m_allowDuplicates;
};