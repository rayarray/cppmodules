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
		using reverse_iterator
			= typename std::stack<_Tp, _Container>::container_type::reverse_iterator;
		using const_reverse_iterator
			= typename std::stack<_Tp, _Container>::container_type::const_reverse_iterator;

	public:
		MutatedStack() : std::stack<_Tp, _Container>() {}
		MutatedStack(const MutatedStack& copy) : std::stack<_Tp, _Container>(copy.c) {}
		~MutatedStack() {}
		
		MutatedStack& operator=(const MutatedStack& assign) { this->c = assign.c; return *this; }

		iterator begin() { return this->c.begin(); }
		const_iterator cbegin() const { return this->c.cbegin(); }
		iterator end() { return this->c.end(); }
		const_iterator cend() const { return this->c.cend(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		const_reverse_iterator rcbegin() const { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rcend() const { return this->c.rend(); }

		
};

#include "MutatedStack.tpp"

#endif