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

double customFunction(double x)
{
    return 1.7159 * tanh(2.0/3.0 * x);
}

double	alphareajuste(double alpha, double *erreure)
{
	double i;
	i = 2 / (erreure[0] + erreure[1]);
	if ( i < 0)
		i *= -1;
	return (i);
}

/*double	maxerreure = 0;
	for (int i = 0; i < 2; i++)
	{
		if (target[i] = 1)
			maxerreure += erreure[i];
		else
			maxerreure += (erreure[i] - 0.5);
	}
	alpha = maxerreure;
	if (alpha < 0)
		alpha *= -1;
	return (alpha);*/