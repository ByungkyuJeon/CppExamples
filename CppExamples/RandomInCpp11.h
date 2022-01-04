#pragma once
#include <ctime>
#include <cstdlib>
#include <random>

// Getting Random Number In Cpp +11
//
// C style random
// 
// c style random doesn't guarantee perfectly arranged random
int getCRandom(int limit)
{
	// when limit is 4
	// pretend is std::rand() value is from 0~9
	// 
	// return value will be 0
	// when 'std::rand()' values are 0, 4, 8
	// it's 3 possibilities
	//
	// return value will be 1
	// when 'std::rand()' value's unit digit numbers are 1, 5, 9
	// it's 3 possibilities
	//
	// return value will be 2
	// when 'std::rand()' value's unit digit numbers are 2, 6
	// it's 2 possibilities
	//
	// return value will be 3
	// when 'std::rand()' value's unit digit numbers are 3, 7
	// it's 2 possibilities
	std::srand(std::time(NULL));
	return (std::rand() % limit);
}

// Cpp style random
int getCppRandom(int limit)
{
	int seedNum = 99;
	std::random_device rd;

#ifndef _WIN64
	std::mt19937_64 randomEngine(seedNum); // seedNum or rd
	#else
	std::mt19937 randomEngine(seedNum); // seedNum or rd
#endif // !_WIN64

	// can use
	// 
	// 1. uniform_int_distribution
	// 2. uniform_real_distribution
	// 3. bernoulli_distribution
	// 4. binomial_distribution
	// 5. negative_binomial_distribution
	// 6. geometric_distribution
    // 7. poisson_distribution
	// 8. exponential_distribution
	// 9. gamma_distribution
	// 10. weibull_distribution
	// 11. extreme_value_distribution
	// 12. normal_distribution
	// 13. lognormal_distribution
	// 14. chi_squared_distribution
	// 15. cauchy_distribution
	// 16. fisher_f_distribution
	// 17. student_t_distribution
	// 18. discrete_distribution
	// 19. piecewise_constant_distribution
	// 20. piecewise_linear_distribution
	std::uniform_int_distribution<int> dist(0, 99);
	return dist(randomEngine);
}