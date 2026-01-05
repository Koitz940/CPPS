/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:13:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 20:13:00 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char* PmergeMe::Overflow::what() const throw() {return this->msg;}
PmergeMe::Overflow::Overflow(const char* msg): msg(msg) {}

PmergeMe::PmergeMe(): vec(1), deq(1) {
	this->vec.push_back(1);
	this->deq.push_back(1);
}
PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	this->vec = other.vec;
	this->deq = other.deq;

	return *this;
}

PmergeMe::PmergeMe(std::string& str) {
	std::string::const_iterator it;
	num cur = 0;

	it = str.begin();
	while (it != str.end()) {
		while (it != str.end() && isdigit(*it)) {
			cur = cur * 10 + (*it - '0');
			if (cur < 0)
				throw Overflow("Number bigger than the maximum");
			++it;
		}
		this->vec.push_back(cur);
		this->deq.push_back(cur);
		cur = 0;
		if (it != str.end())
			++it;
	}
}

void PmergeMe::validate(const std::string& input) {
	std::string::const_iterator it = input.begin();

	while (1) {
		while (isdigit(*it)) {
			it++;
			if (it == input.end())
				return ;
		}
		if (*it != ' ')
			throw(Overflow("Unexpected character"));
		it++;
	}
}

static void removeExtraSpaces(std::string &str) {
    std::string result;
    bool space = false;

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (std::isspace(*it)) {
            if (!space) {
                result += ' ';
                space = true;
            }
        } else {
            result += *it;
            space = false;
        }
    }

    str = result;
}

void PmergeMe::correct(std::string& str) {
	if (str.size() == 0)
		throw(Overflow("Error: Empty argument"));

	bool check = true;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isspace(*it)) {
			check = false;
			break;
		}
	}
	if (check)
		throw(Overflow("Error: Empty argument"));
	std::string answer(str);

	answer = answer.substr(answer.find_first_not_of(' '), answer.find_last_not_of(' ') - answer.find_first_not_of(' ') + 1);

	removeExtraSpaces(answer);
	str = answer;
}

template <typename T>
void sortVec(std::vector<T>& vec) {
	switch (vec.size()) {
		case 0: return;
		case 1: return;
		case 2:
			if (vec[0] > vec[1])
				swap(vec[0], vec[1]);
			return;
	}
	
	std::vector<T> vec1 = std::vector<T>();
	std::vector<T> vec2 = std::vector<T>();
	typename std::vector<T>::const_iterator it = vec.begin();
	T first;
	T second;

	while (it != vec.end()) {
		first = *it;
		it++;
		if (it == vec.end()) {
			vec1.push_back(first);
			break;
		}
		second = *it;
		it++;
		if (first > second) {
			vec1.push_back(first);
			vec2.push_back(second);
			continue;
		}
		vec1.push_back(second);
		vec2.push_back(first);
	}
	sortVec(vec1);
	for (typename std::vector<T>::const_iterator ite = vec2.begin(); ite != vec2.end(); ite++)
		vec1.insert(vec1.begin() + locateVec(vec1, *ite), *ite);
	vec = vec1;
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
int locateVec(std::vector<T>& vec, T n) {
	int i = 0;
	int j = vec.size();
	int middle;

	while (i < j) {
		middle = (i + j) / 2;
		if (vec[middle] == n)
			return middle;
		else if (vec[middle] < n)
			i = middle + 1;
		else
			j = middle;
	}
	return i;
}

template <typename T>
void sortDeq(std::deque<T>& deq) {
	switch (deq.size()) {
		case 0: return;
		case 1: return;
		case 2:
			if (deq[0] > deq[1])
				swap(deq[0], deq[1]);
			return;
	}
	
	std::deque<T> deq1 = std::deque<T>();
	std::deque<T> deq2 = std::deque<T>();
	typename std::deque<T>::const_iterator it = deq.begin();
	T first;
	T second;

	while (it != deq.end()) {
		first = *it;
		it++;
		if (it == deq.end()) {
			deq1.push_back(first);
			break;
		}
		second = *it;
		it++;
		if (first > second) {
			deq1.push_back(first);
			deq2.push_back(second);
			continue;
		}
		deq1.push_back(second);
		deq2.push_back(first);
	}
	sortDeq(deq1);
	for (typename std::deque<T>::const_iterator ite = deq2.begin(); ite != deq2.end(); ite++)
		deq1.insert(deq1.begin() + locateDeq(deq1, *ite), *ite);
	deq = deq1;
}

template <typename T>
int locateDeq(std::deque<T>& deq, T n) {
	int i = 0;
	int j = deq.size();
	int middle;

	while (i < j) {
		middle = (i + j) / 2;
		if (deq[middle] == n)
			return middle;
		else if (deq[middle] < n)
			i = middle + 1;
		else
			j = middle;
	}
	return i;
}

void PmergeMe::run() {
	std::clock_t start;
	std::clock_t end;
	float exp = this->vec.size() < 100 ? NS: US;
	std::string unit = this->vec.size() < 100 ? " ns": " us";

	std::cout << "Before: " << this->vec << "\n";
	start = clock();
	sortVec(this->vec);
	end = clock();
	std::cout << "After: " << this->vec << "\n";
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vec : " << (exp * (double)(end - start)) / (double)CLOCKS_PER_SEC << unit <<"\n";

	start = clock();
	sortDeq(this->deq);
	end = clock();
	//std::cout << "After: " << this->deq << "\n";
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::deque : " << (exp * (double)(end - start)) / (double)CLOCKS_PER_SEC << unit << "\n";
	std::cout << end - start;
}

std::ostream& operator<<(std::ostream& out, const std::vector<num>& vec) {
	for (std::vector<num>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it;
		if ((it + 1) != vec.end())
		std::cout << " ";
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const std::deque<num>& deq) {
	for (std::deque<num>::const_iterator it = deq.begin(); it != deq.end(); it++) {
		std::cout << *it;
		if ((it + 1) != deq.end())
		std::cout << " ";
	}
	return out;
}
