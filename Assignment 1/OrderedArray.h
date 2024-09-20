#pragma once

#include "Array.h"

template <typename T>
class OrderedArray : public Array<T> {
public:
	inline OrderedArray(bool allowDuplicates, int size, int growBy = 1) : Array<T>(size, growBy) {
		m_allowDuplicates = allowDuplicates;

		std::cout << "Created new OrderedArray<" << typeid(T).name() << ">"
			<< " with initial size of " << size
			<< " and growth value of " << growBy << ". Duplicates are " << (allowDuplicates ? "allowed." : "not allowed.")
			<< std::endl << std::endl;
	}

	inline virtual void push(T value) override {
		NULLCHECK(this->m_array);

		if (!this->m_allowDuplicates && find(value) != -1) {
			std::cout << "Duplicate entry prevented: " << value << std::endl;
			return;
		}

		if (this->m_numElements >= this->m_maxSize)
			this->expand();

		int i, k;

		
		for (i = 0; i < this->m_numElements; i++) {
			if (this->m_array[i] > value) break;
		}
		

		for (k = this->m_numElements; k > i; k--) {
			this->m_array[k] = this->m_array[k - 1];
		}

		this->m_array[i] = value;
		this->m_numElements++;
	}

	inline virtual int find(T searchKey) const override {
		NULLCHECK(this->m_array);

		int lowerBound = 0, upperBound = this->m_numElements - 1, current = 0;

		while (1) {
			current = (lowerBound + upperBound) >> 1;

			if (this->m_array[current] == searchKey) {
				std::cout << "Found " << searchKey << " at index " << current << '.' << std::endl;
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

	inline bool duplicatesAllowed() { return m_allowDuplicates; }

	inline void allowDuplicates(bool allowed, bool removeExisting = false) { 
		m_allowDuplicates = allowed; 
		std::cout << "Duplicates are " << (allowed ? "now allowed." : "no longer allowed.") << std::endl;
		if (!allowed && removeExisting) removeDuplicates();
	}

private:
	bool m_allowDuplicates;

	void removeDuplicates() {
		int removeCounter = 0;
		for (int i = this->m_numElements - 1; i > 0; i--) {
			if (this->m_array[i] == this->m_array[i - 1]) {
				this->remove(i);
				removeCounter++;
			}
		}

		std::cout << "Removed " << removeCounter << " duplicate(s)." << std::endl;
	}
};