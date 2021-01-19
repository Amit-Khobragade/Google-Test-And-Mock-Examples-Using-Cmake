#ifndef SOMECLASS_H
#define SOMECLASS_H
#include "otherClass.h"

//has an object from the other class
class someClass{
	public:
		someClass( otherClass* oc )
			: toCheck{oc}
		{}
		float method_to_forward( int id ) const;
	private:
		otherClass* toCheck;
};

#endif