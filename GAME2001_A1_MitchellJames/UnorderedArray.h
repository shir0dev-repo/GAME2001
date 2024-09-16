#pragma once

template <typename T> class Array;

template <typename T>
class UnorderedArray : public Array<T> {
public:
	inline UnorderedArray(int size, int growBy = 1) : (size, growBy) {}

	void push(T) const override final;
	void pop() const override final;
	int indexOf(const T&) const override final;
};