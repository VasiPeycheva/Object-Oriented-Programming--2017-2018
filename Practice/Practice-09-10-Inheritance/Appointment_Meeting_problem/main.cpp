#include "Appointment.h"
#include "Meeting.h"
#include <iostream>

bool hasAppointmentWith(Meeting* schedule, int size, const char * name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(schedule[i].getContact(), name) == 0)
			return true;
	}
	return false;
}


int main()
{
	Meeting h("Iva", "staff reduce", "1244", "1350");
	Meeting p("Plamen", "salary change", "1600", "1700");

	Meeting ** sched = new Meeting*[2];
	sched[0] = new Meeting(h);
	sched[1] = new Meeting(p);

	std::cout << hasAppointmentWith(*sched, 2, "Angel"); 

	return 0;
}