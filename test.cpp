#include "test.hpp"

//-------------------------Constructeurs-----------------------//

test::test(void)
{
	this->pri_inputsize = 4;
	this->pri_hiddensize = 4;
	this->pri_outputsize = 2;
	this->pri_alpha = 0.5;
	this->pri_input = new double[4];
    this->pri_hidden = new double[4];
    this->pri_output = new double[2];
	this->pri_target = new double[2];
	this->pri_error = new double[2];

    this->pri_wh = new double*[4];
    for (int i = 0; i < 4; i++)
	{
        this->pri_wh[i] = new double[4];
    }
	this->pri_whg = new double*[4];
    for (int i = 0; i < 4; i++)
	{
        this->pri_whg[i] = new double[4];
    }
    this->pri_wo = new double*[2];
    for (int i = 0; i < 2; i++)
	{
        this->pri_wo[i] = new double[4];
    }
	this->pri_wog = new double*[2];
    for (int i = 0; i < 2; i++)
	{
        this->pri_wog[i] = new double[4];
    }
	return;
}

test::~test(void)
{
	delete[] this->pri_error;
	delete[] this->pri_target;
	delete[] this->pri_xh;
	delete[] this->pri_xo;
	delete[] this->pri_input_data;
	delete[] pri_input;
    delete[] pri_hidden;
    delete[] pri_output;

    for (int i = 0; i < pri_hiddensize; i++)
	{
        delete[] pri_wh[i];
    }
    delete[] pri_wh;

	for (int i = 0; i < pri_hiddensize; i++)
	{
        delete[] pri_whg[i];
    }
    delete[] pri_whg;

    for (int i = 0; i < pri_outputsize; i++)
	{
        delete[] pri_wo[i];
    }
    delete[] pri_wo;

	for (int i = 0; i < pri_outputsize; i++)
	{
        delete[] pri_wog[i];
    }
    delete[] pri_wog;
	return;
}
//------------------set--------------------//

void	test::set_input_data(double *input_data, int len)
{
	this->pri_input_data = new double[len];
	for(int i = 0; i < len; i++) {
		this->pri_input_data[i] = input_data[i];
	}
	return;
}

void	test::set_input_data(double *input_data, double *target, int len)
{
	this->pri_input_data = new double[len];
	for(int i = 0; i < len; i++) {
		this->pri_input_data[i] = input_data[i];
	}

	for(int i = 0; i < this->pri_outputsize; i++)
	{
		this->pri_target[i] = target[i];
	}

	return;
}

void	test::set_input_data(double *input_data, double alpha, double *target, int len)
{
	this->pri_input_data = new double[len];
	for(int i = 0; i < len; i++) {
		this->pri_input_data[i] = input_data[i];
	}

	for(int i = 0; i < this->pri_outputsize; i++)
	{
		this->pri_target[i] = target[i];
	}

	this->pri_alpha = alpha;

	return;
}


//------------------------------init----------------------------//

void	test::reset(void)
{
	this->pri_alpha = 0.5;
	for (int i = 0; i < this->pri_outputsize; i++){
		this->pri_target[i] = 0;
	}
	for (int i = 0; i < this->pri_inputsize; i++){
		this->pri_input[i] = 0;
	}
	for (int i = 0; i < this->pri_hiddensize; i++){
		this->pri_hidden[i] = 0;
	}
	for (int i = 0; i < this->pri_outputsize; i++){
		this->pri_output[i] = 0;
	}
	for (int i = 0; i < this->pri_hiddensize; i++){
		for (int j = 0; j < this->pri_hiddensize; j++){
			this->pri_wh[i][j] = 0.5;
		}
	}
	for (int i = 0; i < this->pri_outputsize; i++){
		for (int j = 0; j < this->pri_hiddensize; j++){
			this->pri_wo[i][j] = 0.5;
		}
	}
	this->pri_wh[1][0] = 1;
	this->pri_wh[0][2] = 2;
	this->pri_wh[3][1] = 0.2;
	this->pri_wh[2][3] = 1.2;
	
	return;
}

void	test::propagate(double *d)
{
	//-------init-------//
	this->pri_xo = new double[this->pri_outputsize];
	for (int i = 0; i < this->pri_outputsize; i++){
		this->pri_xo[i] = 0;
	}
	this->pri_xh = new double[this->pri_inputsize];
	for (int i = 0; i < this->pri_inputsize; i++){
		this->pri_xh[i] = 0;
	}
	for (int i = 0; i < this->pri_inputsize; i++){
		this->pri_input[i] = d[i];
	}

	//--calcules--//

	for(int j = 0; j < this->pri_hiddensize; j++){
		for(int i = 0; i < this->pri_inputsize; i++)
		{
			this->pri_xh[j] += this->pri_wh[j][i] * this->pri_input[i];
		}
	}

	for(int j = 0; j < this->pri_hiddensize; j++){
		this->pri_hidden[j] = sigmoid(this->pri_xh[j]);
	}

	for(int k = 0; k < this->pri_outputsize; k++){
		for(int j = 0; j < this->pri_hiddensize; j++){
			this->pri_xo[k] += this->pri_wo[k][j] * this->pri_hidden[j]; 
		}
	}

	for(int j = 0; j < this->pri_outputsize; j++){
		this->pri_output[j] = sigmoid(this->pri_xo[j]);
		//std::cout << "neurone de sortie " << j << " = " << pri_output[j] << std::endl;
	}
	std::cout << std::endl;
}

void	test::learn(double *target)
{
	double neg[4];
	double neg2;
	for (int k = 0; k < this->pri_outputsize; k++)
	{
		this->pri_error[k] = target[k] - this->pri_output[k];
		//std::cout << "output ERROR" << k << " = " << this->pri_error[k] << std::endl;
	}

	this->pri_alpha = alphareajuste(this->pri_alpha, this->pri_error);

	for (int k = 0; k < this->pri_outputsize; k++){
		for ( int j = 0; j < this->pri_hiddensize; j++){
			neg[k] = this->pri_error[k] * -1;
			this->pri_wog[k][j] = neg[k] * this->pri_output[k] * (1 - this->pri_output[k]) * this->pri_hidden[j];
			std::cout <<  -this->pri_output[k] << std::endl;
		}
	}

	for	(int j = 0; j < this->pri_hiddensize; j++){
		for (int i = 0; i < this->pri_inputsize; i++){
			double	e = 0;
			for (int k = 0; k < this->pri_outputsize; k++)
				e += this->pri_wo[k][j] * this->pri_error[k];
			neg2 = e * -1;
			this->pri_whg[j][i] = neg2 * this->pri_hidden[j] * (1 - this->pri_hidden[j]) * this->pri_input[i];
		}
	}

	for (int k = 0; k < this->pri_outputsize; k++){
		for ( int j = 0; j < this->pri_hiddensize; j++){
			this->pri_wo[k][j] -= this->pri_alpha * this->pri_wog[k][j];
		}
	}
	for	(int j = 0; j < this->pri_hiddensize; j++){
		for (int i = 0; i < this->pri_inputsize; i++){
			this->pri_wh[j][i] -= this->pri_alpha * this->pri_whg[j][i];
		}
	}
	std::cout << std::endl;
	return;
}

void	test::autolearn(void)
{
	this->pri_alpha = 0.5;
	double	test1_1[] = {0,0,0,0};
	double	test1_2[] = {1,1,1,1};
	double	target1[] = {0,0};
	double	test2_1[] = {1,0,0,0};
	double	test2_2[] = {0,0,1,0};
	double	target2[] = {0,1};
	double	test3_1[] = {1,0,1,0};
	double	test3_2[] = {0,1,1,0};
	double	target3[] = {1,0};
	double	test4_1[] = {1,1,1,0};
	double	test4_2[] = {0,1,1,1};
	double	target4[] = {1,1};
	int	i;
	int	mult = 1;
	i = 0;

	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test1_1, target1, 4);
		this->propagate(test1_1);
		this->learn(target1);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test1_2, target1, 4);
		this->propagate(test1_2);
		this->learn(target1);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test2_1, target2, 4);
		this->propagate(test2_1);
		this->learn(target2);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test2_2, target2, 4);
		this->propagate(test2_2);
		this->learn(target2);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test3_1, target3, 4);
		this->propagate(test3_1);
		this->learn(target3);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test3_2, target3, 4);
		this->propagate(test3_2);
		this->learn(target3);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test4_1, target4, 4);
		this->propagate(test4_1);
		this->learn(target4);
		i++;
	}
	i = 0;
	this->pri_alpha -= 0.05;
	while (i < mult)
	{
		this->set_input_data(test4_2, target4, 4);
		this->propagate(test4_2);
		this->learn(target4);
		i++;
	}
	i = 0;
	return;
}

void	test::put_output(void)
{
	for(int j = 0; j < this->pri_outputsize; j++){
		std::cout << "neurone de sortie " << j << " = " << pri_output[j] << std::endl;
	}
	for(int j = 0; j < this->pri_outputsize; j++){
		if(pri_output[j] < 0.5)
			std::cout << "neurone de sortie " << j << " = " << 0 << std::endl;
		else
			std::cout << "neurone de sortie " << j << " = " << 1 << std::endl;

	}
	return;
}

void	test::put_error(void)
{
	for (int k = 0; k < this->pri_outputsize; k++)
	{
		std::cout << "output ERROR" << k << " = " << this->pri_error[k] << std::endl;
	}
	return;
}


int	test::get_error(double *target)
{
	double retun[2];
	retun[0] = this->pri_output[0];
	retun[1] = this->pri_output[1];
	for(int i = 0; i < 2; i++)
	{
		if(retun[i] > 0.5)
		{
			retun[i] = 1.0;
		}
		else
		{
			retun[i] = 0.0;
		}
	}
	for(int i = 0; i < 2; i++)
	{
		if (retun[i] != target[i])
			return 0;
	}
	return 1;
}

void	test::put_poidsh(void)
{
	std::cout << "Couche 1" << std::endl << std::endl;
	for (int i = 0; i < this->pri_hiddensize; i++){
		std::cout << "neurone " << i << " : ";
		for (int j = 0; j < this->pri_hiddensize; j++){
			std::cout << this->pri_wh[i][j] << " : ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	test::put_poidso(void)
{
	std::cout << "Couche sortie" << std::endl << std::endl;
	for (int i = 0; i < this->pri_outputsize; i++){
		std::cout << "neurone " << i << " : ";
		for (int j = 0; j < this->pri_hiddensize; j++){
			std::cout << this->pri_wo[i][j] << " : ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	test::put_poids(void)
{
	this->put_poidsh();
	this->put_poidso();
}