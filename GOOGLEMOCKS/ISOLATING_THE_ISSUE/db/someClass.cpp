#include "someClass.h"

float someClass::method_to_forward( int id ) const{
	return toCheck->method_to_check(id);
}