#ifndef	ADAM_HPP
# define ADAM_HPP

#include "firstIA.hpp"

class	ADAM
{
	protected:

	double	learning_rate;
    double	beta1;
    double	beta2;
    double	epsilon;
    std::vector<std::vector<double>>	m;
    std::vector<std::vector<double>>	v;
    int	t;

	public:

	ADAM(int output_size, double lr = 0.001, double b1 = 0.9, double b2 = 0.999, double eps = 1e-8);
	~ADAM(VOID);

	void	get_learnrate(std::vector<std::vector<double>>& parameters, const std::vector<std::vector<double>>& gradients);
};