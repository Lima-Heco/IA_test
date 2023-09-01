#include "firstIA.hpp"

int	main(void)
{
	test IA;
	int i = 0;
	int	repeat = 0;
	double	alpha;
	double	input_data[] = {0.0,0.0,0.0,0.0};
	double	target[] = {0.0,0.0};
	std::string	commande;

	IA.reset();
	IA.set_input_data(input_data, 4);
	//IA.propagate(input_data);
	std::cout << "Bienvenue dans IA test." << std::endl;
	while (commande != "EXIT")
	{
		std::cout << "commandes :"
			<< std::endl << "- RESET : pour initialiser et restorer le reseau de neurones." << std::endl << "- PROPAGATE : pour lancer le reseau."
			<< std::endl << "- LEARN : pour l'entrainer."
			<< std::endl << "- AUTO_LEARN : pour l'entrainer automatiquement." << std::endl <<" Commande :";
		std::cin >> commande;
		if (commande == "RESET" || commande == "-r")
		{
			std::cin.clear();
			IA.reset();
		}
		if (commande == "PROPAGATE" || commande == "-p")
		{
			std::cout << "entrez la valeure du pixel 1 :";
			std::cin >> input_data[0];
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 2 :";
			std::cin >> input_data[1];
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 3 :";
			std::cin >> input_data[2];
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 4 :";
			std::cin >> input_data[3];
			std::cin.clear();
			IA.set_input_data(input_data, 4);
			IA.propagate(input_data);
			IA.put_output();
		}
		if (commande == "LEARN" || commande == "-l")
		{
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 1 :";
			std::cin >> input_data[0];
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 2 :";
			std::cin >> input_data[1];
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 3 :";
			std::cin >> input_data[2];
			std::cin.clear();
			std::cout << "entrez la valeure du pixel 4 :";
			std::cin >> input_data[3];
			std::cin.clear();
			std::cout << "entrez l'objectif 1 :";
			std::cin >> target[0];
			std::cin.clear();
			std::cout << "entrez l'objectif 2 :";
			std::cin >> target[1];
			std::cin.clear();
			std::cout << "entrez le nombre de repetitions:";
			std::cin >> repeat;
			std::cin.clear();
			/*std::cout << "entrez l'alpha :";
			std::cin >> alpha;
			std::cin.clear();*/
			i = 0;
			while (i < repeat)
			{
				IA.set_input_data(input_data, alpha, target, 4);
				IA.propagate(input_data);
				IA.learn(target);
				IA.propagate(input_data);
				i++;
			}
			IA.put_output();
			IA.put_error();
		}
		if	(commande == "re")
			{
				IA.propagate(input_data);
				IA.learn(target);
				IA.propagate(input_data);
				IA.put_output();
				IA.put_error();
			}

		if (commande == "-t")
		{
			if (tester(&IA) == 0)
			{
				std::cout << "KO" << std::endl;
			}
			else
				std::cout << "OK" << std::endl;
		}

		if	(commande == "-al")
			training(&IA);
		if	(commande == "STATUS" || commande == "-s")
			IA.put_poids();
	}
	return 0;
}