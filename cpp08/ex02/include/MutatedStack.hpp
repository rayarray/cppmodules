#ifndef	MUTATEDSTACK_HPP
# define MUTATEDSTACK_HPP

#include <stack>

template <typename _Tp, class _Container = std::deque<_Tp> >
class _LIBCPP_TEMPLATE_VIS MutatedStack : public std::stack<_Tp, _Container> {
	public:
		typedef _Container									container_type;

		using iterator
			= typename std::stack<_Tp, _Container>::container_type::iterator;
		using const_iterator
			= typename std::stack<_Tp, _Container>::container_type::const_iterator;

//	protected:
//		container_type	c;

	public:
		MutatedStack() : std::stack<_Tp, _Container>() {}
		MutatedStack(const MutatedStack& copy) : std::stack<_Tp, _Container>(copy.c) {}
		~MutatedStack() {}
		
		MutatedStack& operator=(const MutatedStack& assign) { this->c = assign.c; return *this; }

		iterator begin() { return this->c.begin(); };
		const_iterator cbegin() { return this->c.cbegin(); };
		iterator end() { return this->c.end(); };
		const_iterator cend() { return this->c.cend(); };
};

#include "MutatedStack.tpp"

#endif