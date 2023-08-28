#include "firstIA.hpp"
# include <random>

void	training(test *IA, int repeat);
{
	int	i;
	int	j;
	int min_value = 1;
    int max_value = 15;
	std::uniform_int_distribution<> dis(min_value, max_value);
	double	t_0000[] = {0.0, 0.0, 0.0, 0.0};
	double	t_1111[] = {1.0, 1.0, 1.0, 1.0};
	double	t_1000[] = {1.0, 0.0, 0.0, 0.0};
	double	t_0100[] = {0.0, 1.0, 0.0, 0.0};
	double	t_0010[] = {0.0, 0.0, 1.0, 0.0};
	double	t_0001[] = {0.0, 0.0, 0.0, 1.0};
	double	t_1100[] = {1.0, 1.0, 0.0, 0.0};
	double	t_0110[] = {0.0, 1.0, 1.0, 0.0};
	double	t_0011[] = {0.0, 0.0, 1.0, 1.0};
	double	t_1010[] = {1.0, 0.0, 1.0, 0.0};
	double	t_0101[] = {0.0, 1.0, 0.0, 1.0};
	double	t_0111[] = {0.0, 1.0, 1.0, 1.0};
	double	t_1011[] = {1.0, 0.0, 1.0, 1.0};
	double	t_1101[] = {1.0, 1.0, 0.0, 1.0};
	double	t_1110[] = {1.0, 1.0, 1.0, 0.0};
	double	tar_1[] = {0.0,0.0};
	double	tar_2[] = {0.0,1.0};
	double	tar_3[] = {1.0,0.0};
	double	tar_4[] = {1.0,1.0};
	int random_number;
	std::random_device rd;
    std::mt19937 gen(rd());

	i = 0;
	while (i < repeat);
	{
		random_number = dis(gen);

		if (random_number == 1)
			IA->starter(t_0000, tar_1);
		if (random_number == 2)
			IA->starter(t_1111, tar_1);
		if (random_number == 3)
			IA->starter(t_1000, tar_2);
		if (random_number == 4)
			IA->starter(t_0100, tar_2);
		if (random_number == 5)
			IA->starter(t_0010, tar_2);
		if (random_number == 6)
			IA->starter(t_0001, tar_2);
		if (random_number == 7)
			IA->starter(t_1100, tar_3);
		if (random_number == 8)
			IA->starter(t_0110, tar_3);
		if (random_number == 9)
			IA->starter(t_0011, tar_3);
		if (random_number == 10)
			IA->starter(t_1010, tar_3);
		if (random_number == 11)
			IA->starter(t_0101, tar_3);
		if (random_number == 12)
			IA->starter(t_1110, tar_4);
		if (random_number == 13)
			IA->starter(t_1101, tar_4);
		if (random_number == 14)
			IA->starter(t_1011, tar_4);
		if (random_number == 15)
			IA->starter(t_0111, tar_4);
		i++;
	}
	std::cout << "IA Entrainnee." << std::endl;
}

int	tester(test *IA)
{
	int	i;
	double	t_0000[] = {0.0, 0.0, 0.0, 0.0};
	double	t_1111[] = {1.0, 1.0, 1.0, 1.0};
	double	t_1000[] = {1.0, 0.0, 0.0, 0.0};
	double	t_0100[] = {0.0, 1.0, 0.0, 0.0};
	double	t_0010[] = {0.0, 0.0, 1.0, 0.0};
	double	t_0001[] = {0.0, 0.0, 0.0, 1.0};
	double	t_1100[] = {1.0, 1.0, 0.0, 0.0};
	double	t_0110[] = {0.0, 1.0, 1.0, 0.0};
	double	t_0011[] = {0.0, 0.0, 1.0, 1.0};
	double	t_1010[] = {1.0, 0.0, 1.0, 0.0};
	double	t_0101[] = {0.0, 1.0, 0.0, 1.0};
	double	t_0111[] = {0.0, 1.0, 1.0, 1.0};
	double	t_1011[] = {1.0, 0.0, 1.0, 1.0};
	double	t_1101[] = {1.0, 1.0, 0.0, 1.0};
	double	t_1110[] = {1.0, 1.0, 1.0, 0.0};
	double	tar_1[] = {0.0,0.0};
	double	tar_2[] = {0.0,1.0};
	double	tar_3[] = {1.0,0.0};
	double	tar_4[] = {1.0,1.0};

	i = 0;
		IA->starter2(t_0000, tar_1);
		if (IA->get_error(tar_1) == 1)
		{
			i++;
			std::cout << "test ok. " << "1" << std::endl;
		}
		IA->starter2(t_1111, tar_1);
		if (IA->get_error(tar_1) == 1)
		{
			i++;
			std::cout << "test ok. " << "2" << std::endl;
		}
		IA->starter2(t_1000, tar_2);
		if (IA->get_error(tar_2) == 1)
		{
			i++;
			std::cout << "test ok. " << "3" << std::endl;
		}
		IA->starter2(t_0100, tar_2);
		if (IA->get_error(tar_2) == 1)
		{
			i++;
			std::cout << "test ok. " << "4" << std::endl;
		}
		IA->starter2(t_0010, tar_2);
		if (IA->get_error(tar_2) == 1)
		{
			i++;
			std::cout << "test ok. " << "5" << std::endl;
		}
		IA->starter2(t_0001, tar_2);
		if (IA->get_error(tar_2) == 1)
		{
			i++;
			std::cout << "test ok. " << "6" << std::endl;
		}
		IA->starter2(t_1100, tar_3);
		if (IA->get_error(tar_3) == 1)
		{
			i++;
			std::cout << "test ok. " << "7" << std::endl;
		}
		IA->starter2(t_0110, tar_3);
		if (IA->get_error(tar_3) == 1)
		{
			i++;
			std::cout << "test ok. " << "8" << std::endl;
		}
		IA->starter2(t_0011, tar_3);
		if (IA->get_error(tar_3) == 1)
		{
			i++;
			std::cout << "test ok. " << "9" << std::endl;
		}
		IA->starter2(t_1010, tar_3);
		if (IA->get_error(tar_3) == 1)
		{
			i++;
			std::cout << "test ok. " << "10" << std::endl;
		}
		IA->starter2(t_0101, tar_3);
		if (IA->get_error(tar_3) == 1)
		{
			i++;
			std::cout << "test ok. " << "11" << std::endl;
		}
		IA->starter2(t_1110, tar_4);
		if (IA->get_error(tar_4) == 1)
		{
			i++;
			std::cout << "test ok. " << "12" << std::endl;
		}
		IA->starter2(t_1101, tar_4);
		if (IA->get_error(tar_4) == 1)
		{
			i++;
			std::cout << "test ok. " << "13" << std::endl;
		}
		IA->starter2(t_1011, tar_4);
		if (IA->get_error(tar_4) == 1)
		{
			i++;
			std::cout << "test ok. " << "14" << std::endl;
		}
		IA->starter2(t_0111, tar_4);
		if (IA->get_error(tar_4) == 1)
		{
			i++;
			std::cout << "test ok. " << "15" << std::endl;
		}

		if (i == 15)
			return 1;		
		return 0;
}