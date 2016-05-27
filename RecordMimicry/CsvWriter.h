#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "ImageProcess.h"
#include <fstream>
#include <io.h>

class CsvWriter
{
public:
	CsvWriter();
	~CsvWriter();

	bool open(const std::string& filename);
	void release();

	template<typename T>
	void write(const std::vector<std::vector<T>>& arr)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = 0; j < arr[i].size(); ++j)
				stream_ << arr[i][j] << ";"

				stream_ << endl;
		}
	}


	template<typename T>
	void write(const std::vector<T>& arr)
	{
		for (int i = 0; i < arr.size(); ++i)
			stream_ << arr[i] << ";" << endl;
	}


	template<typename T>
	void write(const T& ver)
	{
		stream_ << ver << ";" << endl;
	}



	template<typename T>
	void writePoint(const std::vector<cv::Point_<T>>& arr)
	{
		for (int i = 0; i < arr.size(); ++i)
			stream_ << arr[i].x << ";" << arr[i].y << ";";

		stream_ << endl;
	}


	template<typename T>
	void writePoint(const std::vector<std::vector<cv::Point_<T>>>& arr)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = 0; j < arr[i].size(); ++j)
				stream_ << arr[i][j].x << ";" << arr[i][j].y << ";";

			stream_ << endl;
		}
	}


	template<typename T>
	void writePoint(const cv::Point_<T>& point)
	{
		stream_ << point.x << ";" << point.y << ";" << endl;
	}

private:
	std::ofstream stream_;
};

#endif // CSVWRITER_H