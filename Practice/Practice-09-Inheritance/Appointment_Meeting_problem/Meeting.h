#ifndef __MEETING__HEADER__INCLUDED__
#define __MEETING__HEADER__INCLUDED__
#include "Appointment.h"

class Meeting : public Appointment
{
public:
	Meeting(const char *, const char *, const char start[], const char end[]);
	~Meeting();
	Meeting(const Meeting &);
	Meeting& operator=(const Meeting &);
	
	const char * getContact() const {return contact;}
private:
	void copy(const Meeting &);

private:
	char * contact;
};

#endif // !__MEETING__HEADER__INCLUDED__

