#ifndef Class_HPP
#define Class_HPP

# define DEBUG_MSG "[ DEBUG ]\n\
Why does C have so many brackets and semicolons? It’s like programming \n\
in a room full of punctuation marks that just have to be in the exact \n\
right spot. You miss one, and it’s like the whole code has a breakdown."
# define INFO_MSG "[ INFO ]\n\
Oh, pointers? Yeah, let’s just keep track of memory addresses manually \n\
because that’s totally reasonable. It's like trying to remember where \n\
you left your car in a 50-story parking garage, except there’s also a \n\
void pointer, and you don’t even know what kind of car you’re looking for."
# define WARNING_MSG "[ WARNING ]\n\
So, I write some code, and the program runs. But wait! The output is \n\
completely wrong because one tiny character is in the wrong spot. It’s \n\
like C has a sixth sense for my suffering and decides to punish me with \n\
an invisible semicolon that silently destroys my hopes and dreams in the \n\
background."
# define ERROR_MSG "[ ERROR ]\n\
I tried to debug my code, and now I don’t even know who I am anymore. I \n\
think I might be a pointer to a pointer to a pointer of sadness. C has \n\
consumed my soul, and I’m left here with cryptic segmentation faults and \n\
core dumps, as if it’s laughing at me from the depths of assembly language \n\
hell. I am the memory leak."

#include <iostream>

class Harl
{
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
public:
	// Construct
	Harl();
	// Destroy
	~Harl();
	// Get
	// Set
	// Other
	void	complain(std::string level);
};

#endif