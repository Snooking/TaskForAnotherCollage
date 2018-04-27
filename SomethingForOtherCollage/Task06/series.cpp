#include "series.h"

int Series::_ile = 0;

int Series::ile()
{
	return _ile;
}

Series::Series()
{
	isSeriesUsed = false;
	_ile++;
}

Series::Series(char *series)
{
	int i = 0;
	while (series[i] != '\0') {
		i++;
	}
	_ile++;
	i++;
	_series = new char[i];
	for (int j = 0; j < i; j++) {
		_series[j] = series[j];
	}
	isSeriesUsed = true;
}

Series::Series(Series & other)
{
	_ile++;
	_series = new char[other.dl() + 1];
	for (int i = 0; i < other.dl() + 1; i++) {
		_series[i] = other._series[i];
	}
	isSeriesUsed = true;
}

Series::~Series()
{
	_ile--;
	if (isSeriesUsed)
		delete[] _series;
	isSeriesUsed = false;
}

int Series::dl() const
{
	if (!isSeriesUsed) return 0;
	int i = 0;
	while (_series[i] != '\0') {
		i++;
	}
	return i;
}

Series & Series::operator=(const Series & other)
{
	if (isSeriesUsed)
		delete[] _series;
	_series = new char[other.dl() + 1];
	for (int i = 0; i < other.dl() + 1; i++) {
		_series[i] = other._series[i];
	}
	isSeriesUsed = true;
	return *this;
}

Series & Series::operator+=(const Series & other)
{
	int thisDl = dl();
	int otherDl = other.dl() + 1;
	char* newSeries = new char[thisDl + otherDl];
	for (int i = 0; i < thisDl; i++) {
		newSeries[i] = _series[i];
	}
	for (int i = thisDl, j = 0; i < thisDl + otherDl; i++, j++) {
		newSeries[i] = other._series[j];
	}
	if (isSeriesUsed)
		delete[] _series;
	_series = new char[thisDl + otherDl];
	for (int i = 0; i < thisDl + otherDl; i++) {
		_series[i] = newSeries[i];
	}
	isSeriesUsed = true;
	return *this;
}

Series::operator char*()
{
	return _series;
}