/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:56:53 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:03:50 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    std::cout << "=== Correct polymorphism ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << meta->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    meta->makeSound(); // Animal sound
    dog->makeSound();  // Woof
    cat->makeSound();  // Meow

    delete meta;
    delete dog;
    delete cat;

    std::cout << std::endl;
    std::cout << "=== Wrong polymorphism ===" << std::endl;

    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();

    std::cout << wmeta->getType() << std::endl;
    std::cout << wcat->getType() << std::endl;

    wmeta->makeSound(); // WrongAnimal sound
    wcat->makeSound();  // WrongAnimal sound (NOT Meow!)

    delete wmeta;
    delete wcat;

    return 0;
}


