#ifndef MY_ARRAY
#define MY_ARRAY
#include <vector>

template <class T>
class my_array {
private:
	class MyMaskedArray{
		const my_array<bool>& mask;
		my_array<T> &ref;
	public:
		MyMaskedArray(const my_array<bool>& m, my_array<T> &r)
			: mask(m), ref(r) {};
		my_array<T>& operator=(T t)
		{


			for (size_t i = 0; i < mask.w(); i++)
			{
				for (size_t j = 0; j < mask.h(); j++)
				{
					if (mask(i, j))
						ref(i, j) = t;
				}
			}
			return ref;
		}
	};
public:
	size_t w() const { return data.size(); }
	size_t h() const { return data[0].size(); }
	my_array() : data(0) {};
	my_array(int w, int h) : data(w, std::vector<T>(h)) {

	};
	my_array(my_array const & other) : data(other.data) {};
	my_array(std::vector<std::vector<T> > d) : data(d) {};
	my_array & operator=(my_array const & other)
	{
		data.resize(other.data.size());
		for (size_t i = 0; i < data.size(); i++)
		{
			data[i].resize(other.data[i].size());
			for (size_t j = 0; j < other.data[i].size(); j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	}
	my_array operator+(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return result;
	}
	my_array operator-(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] - other.data[i][j];
			}
		}
		return result;
	}
	my_array operator*(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] * other.data[i][j];
			}
		}
		return result;
	}
	my_array operator/(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] / other.data[i][j];
			}
		}
		return result;
	}
	my_array operator&(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] & other.data[i][j];
			}
		}
		return result;
	}
	my_array operator|(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] | other.data[i][j];
			}
		}
		return result;
	}
	my_array operator^(my_array const & other) {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = data[i][j] ^ other.data[i][j];
			}
		}
		return result;
	}
	my_array  operator!() {
		my_array<T> result(data.size(), data[0].size());
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = 0; j < data[0].size(); j++)
			{
				result.data[i][j] = !data[i][j];
			}
		}
		return result;
	}
	T & operator()(int i, int j)
	{
		return data[i][j];
	}
	T operator()(int i, int j) const
	{
		return data[i][j];
	}
	MyMaskedArray operator()(const my_array<bool>& mask)
	{
		return MyMaskedArray(mask, *this);
	}
	bool operator==(my_array const & other) const
	{
		return other.data == data;
	}
	bool operator!=(my_array const & other) const
	{
		return !(*this == other);
	}
private:


	std::vector<std::vector<T> > data;


};

#endif
