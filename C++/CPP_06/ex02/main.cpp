/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:25:52 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/10 19:10:21 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	srand(time(NULL));
	int	i = rand() % 3;
	switch(i)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
	}
	return (NULL);
}

// try catch, try catch, try catch- sends multiple errors or doesn't try the rest if A throws error
// try {tout} catch sends only first error
// can't try try try catch
// this func attempts to cast p to type A, if p != A std::bad_cast exception automatically thrown
void	identify(Base& p)
{
	std::cout << "----------- Check class type using reference -----------\n";
	try
	{
		if (&dynamic_cast<A&>(p))
			std::cout << "Actual type: A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			if (&dynamic_cast<B&>(p))
				std::cout << "Actual type: B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				if (&dynamic_cast<C&>(p))
					std::cout << "Actual type: C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}

}

// dynamic cast checks conversion between base class ptr and derived class
// this func attempts to cast p to type A, if p != A result is NULL
// safter as no risk of throwing exceptions
void	identify(Base* p)
{
	std::cout << "----------- Check class type using pointer -----------\n";
	if (dynamic_cast<A*>(p))
		std::cout << "Actual type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Actual type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Actual type: C" << std::endl;
	else
		std::cout << "Conversion failed, dynamic_cast returned null" << std::endl;
}

int	main(void)
{
	// generate derived class using ptr to base class
	Base *base1 = generate();

	// check derived class type using two different functions
	// with and without using pointer
	identify(base1);
	identify(*base1);

	delete base1;
	return (0);
}
