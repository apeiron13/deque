#include "deque.hpp"



//void nostd::deque::assign(nostd::deque::size_type count, const std::string& value);
//void nostd::deque::assign(nostd::deque::const_iterator b, nostd::deque::const_iterator e);
//
//// Element access
//nostd::deque::reference at(nostd::deque::size_type idx)
//{
//	return ;
//}
//nostd::deque::const_reference at(nostd::deque::size_type idx) const;
//
//nostd::deque::reference nostd::deque::operator[](nostd::deque::size_type idx);
//nostd::deque::const_reference nostd::deque::operator[](nostd::deque::size_type idx) const;
//
//nostd::deque::reference nostd::deque::front();
//nostd::deque::const_reference nostd::deque::front() const;
//
//nostd::deque::reference nostd::deque::back();
//nostd::deque::const_reference nostd::deque::back() const;
//
//std::string* nostd::deque::data();
//
//// Capacity
//bool nostd::deque::empty() const;
//nostd::deque::size_type nostd::deque::size() const;
//nostd::deque::size_type nostd::deque::max_size() const;
//
//// Reserve front and back capacity, in one operation.
//void nostd::deque::reserve(nostd::deque::size_type front, nostd::deque::size_type back);
//
//// To achieve interface parity with std::vector, capacity() returns capacity_back();
//nostd::deque::size_type nostd::deque::capacity() const;
//
//void nostd::deque::shrink_to_fit();
//
//// Modifiers
//void clear();
//
//nostd::deque::iterator insert(nostd::deque::const_iterator it, const std::string& value);
//nostd::deque::iterator insert(nostd::deque::const_iterator it, nostd::deque::size_type count, const std::string& value);
//nostd::deque::iterator insert(nostd::deque::const_iterator it, nostd::deque::const_iterator b, nostd::deque::const_iterator e);
//
//nostd::deque::iterator erase(nostd::deque::const_iterator it);
//nostd::deque::iterator erase(nostd::deque::const_iterator b, nostd::deque::const_iterator e);
//
//void nostd::deque::push_back(const std::string& value);
//void nostd::deque::push_front(const std::string& value);
//
//void nostd::deque::pop_back();
//void nostd::deque::pop_front();
//
//// To achieve interface parity with std::vector, resize() performs resize_back();
//void nostd::deque::resize(nostd::deque::size_type count);
//void nostd::deque::resize(nostd::deque::size_type count, const std::string& value);
//
//void nostd::deque::swap(deque& other);
//
//bool nostd::deque::operator==(const deque& lhs);
//bool nostd::deque::operator!=(const deque& lhs);
//
//bool nostd::deque::operator<(const deque& lhs);
//bool nostd::deque::operator<=(const deque& lhs);
//
//bool nostd::deque::operator>(const deque& lhs);
//bool nostd::deque::operator>=(const deque& lhs);
//void nostd::swap(deque& rhs);