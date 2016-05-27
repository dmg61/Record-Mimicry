#include "CsvWriter.h"

CsvWriter::CsvWriter()
{
}


CsvWriter::~CsvWriter()
{
	stream_.close();
}

bool CsvWriter::open(const std::string& filename)
{
	//if (access(filename.c_str(), 0) == -1)
	//	return false;

	stream_.open(filename);
	return true;
}

void CsvWriter::release()
{
	stream_.close();
}
