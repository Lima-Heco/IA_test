#include "firstIA.hpp"

double	sigmoid(double x)
{
	double result;

	result = 1.0 / (1.0 + std::exp(-x));
	return (result);
}

double	relu(double x)
{
	if (x > 0)
		return (x);
	return (0.0);
}

double binary_cross_entropy(double p, double q)
{
    return - (p * log(q) + (1 - p) * log(1 - q));
}

double customFunction(double x)
{
    return 1.7159 * tanh(2.0/3.0 * x);
}
