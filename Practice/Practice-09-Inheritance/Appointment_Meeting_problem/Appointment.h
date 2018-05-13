#ifndef __APPOINTMENT__HEADER__INCLUDED__
#define __APPOINTMENT__HEADER__INCLUDED__

class Appointment
{
public:
	Appointment(const char *, const char[], const char[]);
	~Appointment();
	Appointment(const Appointment &);
	Appointment& operator=(const Appointment &);

private:
	void copy(const Appointment &);
private:
	char * description;
	char start[8];
	char end[8];
};

#endif // !__APPOINTMENT__HEADER__INCLUDED__
