#include "Class.hpp"

// Construct
Class::Class () {}
Class::Class (std::string name) : _name(name) {}
// Destruct
Class::~Class() {}
// Get
std::string	Class::getName() { return _name; }
// Set
void	Class::setName(std::string name) { _name = name; }
// Other