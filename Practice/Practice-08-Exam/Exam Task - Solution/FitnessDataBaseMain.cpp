#include<iostream>

#include"Client.h"
#include"Fitness.h"

int main() {
	/*Client client1("Paco", 22, 85);
	Client client2("Vasi", 23, 103);
	Client client3("Mitko", 22, 34);
	Client client4("Vanaka", 23, 82);
	Client client5("Gosho", 101, 232);
	client1.print();

	Fitness f1("Fitness One");

	f1.addClient(client1);
	f1.addClient(client2); 
	f1.addClient(client3); 
	f1.addClient(client4);
	f1.addClient(client5);
	f1.print();
	f1.serializeFitness();*/

	
	Fitness f1("Fitness One");
	f1.deserializeFitness("Fitness One.dat");
	f1.sort();
	f1.print();
	f1.reportFitness();
	return 0;
}