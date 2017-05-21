#ifndef CLASSINTERVALFREQT_H
#define CLASSINTERVALFREQT_H

#include <QWidget>
#include <array>

template<typename T>
using _vct = std::vector<T>;
using _oda = std::array<int, 2>; // One Dimensional Array.

namespace Ui {
class ClassIntervalFreqT;
}

class ClassIntervalFreqT : public QWidget
{
	Q_OBJECT

public:
	explicit ClassIntervalFreqT(_vct<double> &numeric_data, QWidget *parent = 0);
	~ClassIntervalFreqT();

private slots:
	void showFreqPolygon();
	void showHistogram();
	void showOgive();

private:
	Ui::ClassIntervalFreqT *ui;

	// _oda m_classIntervalRange; // Holds the class interval range.
	_vct<int> m_absoluteFreq;
	_vct<int> m_accAbsoluteFreq;
	_vct<int> m_classMarks;
	_vct<double> m_relativeFreq;
	_vct<double> m_accRelativeFreq;
	_vct<double> m_relativePrcntgs;
	_vct<double> m_accRelativePrcntgs;
	_vct<double> m_rawNumericData;
	_vct<_oda> m_allClassIntervals; // Holds all the class interval ranges.
	int m_totalElements;

	// Central trends:
	double m_arithmeticAverage;
	double m_geometricAverage;
	double m_mode;
	double m_median;
	void calculateAverages();

	// Position trends:
	std::array<double, 4> m_quartiles;
	std::array<double, 6> m_sextiles;
	std::array<double, 10> m_deciles;
	std::array<double, 100> m_percentiles;

	// Measures of dispersion:
	double m_range;
	double m_standardDeviation;
	double m_variance;
	double m_varianceCoefficient;
	double m_coefficientPearson;
	double m_coefficientBowley;
	double m_coefficientKurtosis;

	int getTotalRealAmplitude();
	void getClassIntervalRanges(double classInterval);
	void getClassMarks();
	void getSingleClassIntervalRange();
	void vectorialCalculations();
	void buildTable();

	template<typename T>
	void makeACMFreqTable(_vct<T> &mainFreq, _vct<T> &ACMFreq);
};

#endif // CLASSINTERVALFREQT_H
