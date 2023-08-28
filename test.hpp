#ifndef	TEST_HPP
# define TEST_HPP

#include "firstIA.hpp"

class	test
{
	private:

		//--learn--//
		double	pri_alpha;
		double	*pri_error;
		double	*pri_target;
		double	**pri_wog;
		double	**pri_whg;
		//--propagate--//
		double	*pri_xh;
		double	*pri_xo;
		double	*pri_input_data;
		//--nombre_de_neurones--//
		int	pri_inputsize;
		int	pri_hiddensize;
		int	pri_outputsize;
		//--valeurs_de_neurones--//
		double	*pri_input;
		double	*pri_hidden;
		double	*pri_output;
		//--poids_synaptique--//
		double	**pri_wh;
		double	**pri_wo;

	public:

		//--constructeur--//
		test(void);
		~test(void);
		//--utils--//
		void	reset(void);
		void	propagate(double *d);
		void	learn(double *target);
		void	starter(double *input, double *target);
		void	starter2(double *input, double *target);
		//--set--//
		void	set_input_data(double *input_data, int len);
		void	set_input_data(double *input_data, double *target, int len);
		void	set_input_data(double *input_data, double alpha, double *target, int len);
		//--put--//
		void	put_output(void);
		void	put_error(void);
		void	put_poidsh(void);
		void	put_poidso(void);
		void	put_poids(void);
		int	get_error(double *target);
		int	get_error(void);
};

int	tester(test *IA);
double	sigmoid(double x);
double	relu(double x);
double	customFunction(double x);
double	alphareajuste(double alpha, double *erreure);
void	training(test *IA);

#endif