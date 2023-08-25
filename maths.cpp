#include "firstIA.hpp"

double	sigmoid(double x)
{
	double result;

	result = 1.0 / (1.0 + std::exp(-x));
	return (result);
}

double	alphareajuste(double alpha, double *erreure)
{
	double	maxerreure = 0;
	for (int i = 0; i < 2; i++)
	{
		if (erreure[i] > 0)
			maxerreure += (erreure[i] - 0.51);
		else
			maxerreure += (erreure[i] - 0.5);
	}
	alpha = maxerreure;
	if (alpha < 0)
		alpha *= -1;
	return (alpha);
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