#pragma once
#include <vector>

template<typename T>
class GridTiles
{
public:
	GridTiles();
	GridTiles(unsigned int Width, unsigned int Height);
	GridTiles(unsigned int Width, unsigned int Height, const T &Value);
	void Set(unsigned int x, unsigned int y, const T &Value);
	T Get(unsigned int x, unsigned int y) const;
	const T&Ref(unsigned int x, unsigned int y) const;
	T&Ref(unsigned int x, unsigned int y);
	unsigned int Width() const;
	unsigned int Height() const;
private:
	unsigned int W;
	size_t Linearize(unsigned int x, unsigned int y) const;
	std::vector<T> Data;
};

template<typename T>
GridTiles<T>::GridTiles(unsigned int Width, unsigned int Height, const T &Value)
	: W(Width), Data(Width * Height, Value)
{
}

template<typename T>
GridTiles<T>::GridTiles(unsigned int Width, unsigned int Height)
	: W(Width), Data(Width * Height)
{
}

template<typename T>
GridTiles<T>::GridTiles()
	: GridTiles(0, 0)
{
}

template<typename T>
size_t GridTiles<T>::Linearize(unsigned int x, unsigned int y) const
{
	return (size_t)x + (size_t)W * (size_t)y;
}

template<typename T>
void GridTiles<T>::Set(unsigned int x, unsigned int y, const T &Value)
{
	Data[Linearize(x, y)] = Value;
}

template<typename T>
T GridTiles<T>::Get(unsigned int x, unsigned int y) const
{
	return Data[Linearize(x, y)];
}

template<typename T>
const T&GridTiles<T>::Ref(unsigned int x, unsigned int y) const
{
	return Data[Linearize(x, y)];
}

template<typename T>
T&GridTiles<T>::Ref(unsigned int x, unsigned int y)
{
	return Data[Linearize(x, y)];
}

template<typename T>
unsigned int GridTiles<T>::Width() const
{
	return W;
}

template<typename T>
unsigned int GridTiles<T>::Height() const
{
	return (unsigned int)(Data.size() / (size_t)W);
}