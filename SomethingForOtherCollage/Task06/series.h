#ifndef SERIES
#define SERIES

#include <iostream>

class Series {
public:
	Series();
	Series(char*);
	Series(Series&);
	~Series();
	int dl() const;
	Series& operator=(const Series&);
	Series& operator+=(const Series&);
	operator char*();
	static int ile();
	friend Series operator+(const Series&, const Series&);
	friend std::ostream& operator<<(std::ostream&, const Series&);
	friend std::istream& operator>>(std::istream&, Series&);
private:
	static int _ile;
	char* _series;
	bool isSeriesUsed;
};

#endif