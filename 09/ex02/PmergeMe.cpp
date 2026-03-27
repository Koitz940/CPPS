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
	this->vecTime = 0;
	this->deqTime = 0;
	this->valTime = 0;
}
PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	this->vec = other.vec;
	this->deq = other.deq;
	this->vecTime = other.vecTime;
	this->deqTime = other.deqTime;
	this->valTime = other.valTime;

	return *this;
}

PmergeMe::PmergeMe(std::string& str, clock_t valTime) {
	std::string::const_iterator it;
	num cur;
	std::clock_t start;
	std::clock_t end;
	double exp;

	this->valTime = valTime;
	start = clock();
	cur = 0;
	it = str.begin();
	while (it != str.end()) {
		while (it != str.end() && isdigit(*it)) {
			cur = cur * 10 + (*it - '0');
			if (cur < 0)
				throw Overflow("Number bigger than the maximum");
			++it;
		}
		this->vec.push_back(cur);;
		cur = 0;
		if (it != str.end())
			++it;
	}

	end = clock();
	exp = this->vec.size() < 1000? US: MS;
	this->vecTime = exp * ((double)(end - start)) / CLOCKS_PER_SEC;

	start = clock();
	cur = 0;
	it = str.begin();
	while (it != str.end()) {
		while (it != str.end() && isdigit(*it)) {
			cur = cur * 10 + (*it - '0');
			if (cur < 0)
				throw Overflow("Number bigger than the maximum");
			++it;
		}
		this->deq.push_back(cur);;
		cur = 0;
		if (it != str.end())
			++it;
	}

	end = clock();
	this->deqTime = exp * ((double)(end - start)) / CLOCKS_PER_SEC;
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
		throw(Overflow("Empty argument"));

	bool check = true;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isspace(*it)) {
			check = false;
			break;
		}
	}
	if (check)
		throw(Overflow("Empty argument"));
	std::string answer(str);

	answer = answer.substr(answer.find_first_not_of(' '), answer.find_last_not_of(' ') - answer.find_first_not_of(' ') + 1);

	removeExtraSpaces(answer);
	str = answer;
}

template <typename T>
void sortVec(std::vector<T>& vec) {
    if (vec.size() <= 1)
        return;
    if (vec.size() == 2) {
        if (vec[1] < vec[0])
            std::swap(vec[0], vec[1]);
        return;
    }

    bool isOdd = vec.size() % 2;
    T odd;
    if (isOdd) {
        odd = vec.back();
    }

    std::vector<T> mainChain;
	std::vector<T> pend;

	mainChain.reserve(vec.size() / 2);
	pend.reserve(vec.size() / 2);

    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1]) {
			mainChain.push_back(vec[i + 1]);
			pend.push_back(vec[i]);
		}
        else {
			mainChain.push_back(vec[i]);
			pend.push_back(vec[i + 1]);
		}
    }
    sortVec(mainChain);

	if (isOdd)
        mainChain.insert(mainChain.begin() + locateVec(mainChain, odd), odd);

	if (vec.size() > 0) {
		mainChain.insert(mainChain.begin() + locateVec(mainChain, pend[0]), pend[0]);
	}
	num cur = 1;
	num prev = 1;
	num temp;
	while (cur < (num)pend.size()) {
		for (num j = cur - 1; j > prev - 1; j--) {
			mainChain.insert(mainChain.begin() + locateVec(mainChain, pend[j]), pend[j]);
		}
		temp = cur;
		cur = cur + 2 * prev;
		prev = temp;
	}
	for (num j = pend.size() - 1; j > prev - 1; j--) {
		mainChain.insert(mainChain.begin() + locateVec(mainChain, pend[j]), pend[j]);
	}

    vec = mainChain;
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
size_t locateVec(std::vector<T>& vec, T n) {
	size_t i = 0;
	size_t j = vec.size();
	size_t middle;

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
    if (deq.size() <= 1)
        return;
    if (deq.size() == 2) {
        if (deq[1] < deq[0])
            std::swap(deq[0], deq[1]);
        return;
    }

    bool isOdd = deq.size() % 2;
    T odd;
    if (isOdd) {
        odd = deq.back();
    }

    std::deque<T> mainChain;
	std::deque<T> pend;

    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        if (deq[i] < deq[i + 1]) {
			mainChain.push_back(deq[i + 1]);
			pend.push_back(deq[i]);
		}
        else {
			mainChain.push_back(deq[i]);
			pend.push_back(deq[i + 1]);
		}
    }

    sortDeq(mainChain);

	if (isOdd)
        mainChain.insert(mainChain.begin() + locateDeq(mainChain, odd), odd);

	if (deq.size() > 0)
        mainChain.insert(mainChain.begin() + locateDeq(mainChain, pend[0]), pend[0]);

	num cur = 1;
	num prev = 1;
	num temp;
	while (cur < (num)pend.size()) {
		for (num j = cur - 1; j > prev - 1; j--) {
			mainChain.insert(mainChain.begin() + locateDeq(mainChain, pend[j]), pend[j]);
		}
		temp = cur;
		cur = cur + 2 * prev;
		prev = temp;
	}
	for (num j = pend.size() - 1; j > prev - 1; j--) {
		mainChain.insert(mainChain.begin() + locateDeq(mainChain, pend[j]), pend[j]);
	}
    deq = mainChain;
}

template <typename T>
size_t locateDeq(std::deque<T>& deq, T n) {
	size_t i = 0;
	size_t j = deq.size();
	size_t middle;

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

template <typename T>
static bool vecsorted(std::vector<T>& vec) {
	for (size_t i = 0; i + 1 < vec.size(); i++) {
		if (vec[i] > vec[i+1])
			return (false);
	}
	return (true);
}

template <typename T>
static bool deqsorted(std::deque<T>& vec) {
	for (size_t i = 0; i + 1 < vec.size(); i++) {
		if (vec[i] > vec[i+1])
			return (false);
	}
	return (true);
}

void PmergeMe::run() {
	std::clock_t start;
	std::clock_t end;
	float exp = this->vec.size() < 1000? US: MS;
	std::string unit = this->vec.size() < 1000? " us": " ms";
	double sortTime;
	double valT = (MS * (double)this->valTime) / CLOCKS_PER_SEC;

	std::cout << "Time to validate the data: " << valT << " ms" <<"\n\n";
	std::cout << "Using std::vector\n";
	std::cout << "Before: " << this->vec << "\n";
	start = clock();
	sortVec(this->vec);
	end = clock();
	if (!vecsorted(this->vec)) {
		std::cout << "sorting failed!\n";
		return ;
	}
	std::cout << "After: " << this->vec << "\n";
	sortTime = (exp * (double)(end - start)) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to sort a range of " << this->vec.size() << " elements with std::vector : " << sortTime << unit <<"\n";
	std::cout << "Time to create container + sort a range of " << this->vec.size() << " elements with std::vector : " << sortTime + this->vecTime << unit <<"\n";
	std::cout << "Total time with std::vector : " << (sortTime) * (MS/exp) + this->vecTime * (MS/exp) + valT << " ms" << "\n\n";

	start = clock();
	sortDeq(this->deq);
	end = clock();

	if (!deqsorted(this->deq)) {
		std::cout << "sorting failed!\n";
		return ;
	}
	sortTime = (exp * (double)(end - start)) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to sort a range of " << this->deq.size() << " elements with std::deque : " << sortTime << unit <<"\n";
	std::cout << "Time to create container + sort a range of " << this->vec.size() << " elements with std::deque : " << sortTime + this->deqTime << unit <<"\n";
	std::cout << "Total time with std::deque : " << (sortTime) * (MS/exp) + this->deqTime * (MS/exp) + valT << " ms" << "\n";
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
