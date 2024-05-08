#include "iter.hpp"

int main(void) {
	{	int 	int_arr[] = { -321322, 322, -1, 0, 65535, 41 };
		size_t	int_arr_len = sizeof(int_arr) / sizeof(int_arr[0]);
		::iter(int_arr, int_arr_len, printElem<int>);
		::iter(int_arr, int_arr_len, incrementAndPrintElem<int>);
	}
	{	std::string	str_arr[] = { "foo", "bar", "baz", "ber", "biz" };
		size_t		str_arr_len = 5;

		::iter(str_arr, str_arr_len, printElem<std::string>);
	}
}