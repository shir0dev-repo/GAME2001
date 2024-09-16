#pragma once

template <typename T>
class Array {
public:

	Array<T>(int size, int growBy = 1);
	~Array<T>();

	virtual void push(T) const = 0;
	virtual void pop() const = 0;
	virtual int indexOf(const T&) const = 0;

	void remove(int) final;
	void clear() final;

	T& operator[](int index) final;

	inline int getSize() final { return m_numElements; }
	inline int getMaxSize() final { return m_maxSize; }
	inline int getGrowSize() final { return m_growSize; }
	inline void setGrowSize(int value) final { m_growSize = value > -1 ? value : 0; }

protected:
	T* m_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;

	bool expand() final;
};