#ifndef __TEMPERATURE__SENSOR__HEADER__INCLUDED__
#define __TEMPERATURE__SENSOR__HEADER__INCLUDED__

class TemperatureSensor
{
public:
	TemperatureSensor();
	TemperatureSensor(const char*);
	TemperatureSensor(const TemperatureSensor&);
	TemperatureSensor& operator=(const TemperatureSensor&);
	~TemperatureSensor();

	const char* getDescription() const;
	void setDescription(const char*);

	unsigned short getID() const;
	void setNewID();
	
	float getTemperature() const;

private:
	void copyFrom(const TemperatureSensor&);
	void freeData();
	float randomFloat() const;

private:
	char* description;
	unsigned int id;
};

#endif // !__TEMPERATURE__SENSOR__HEADER__INCLUDED__

