/*
James Felts 2015
*/
#ifndef NUMBERISPOWEROF2_H
#define NUMBERISPOWEROF2_H

namespace Utils
{
	//checks at compile time if a given number is a power of 2
	template<int i>
	struct numberIsPowerOf2
	{
		constexpr static bool value = numberIsPowerOf2<i/2>::value;
	};

	template<>
	struct numberIsPowerOf2<2>
	{
		constexpr static bool value = true;
	};

	template<>
	struct numberIsPowerOf2<1>
	{
		constexpr static bool value = false;
	};

	template<>
	struct numberIsPowerOf2<0>
	{
		constexpr static bool value = false;
	};

	template<>
	struct numberIsPowerOf2<-2>
	{
		constexpr static bool value = true;
	};

	template<>
	struct numberIsPowerOf2<-1>
	{
		constexpr static bool value = false;
	};
}
#endif