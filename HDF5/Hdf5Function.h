#include <iostream>
#include <string>
#include <ctime>
#include "hdf5.h"

#ifndef HDF5FUNCTION_H_
#define HDF5FUNCTION_H_
using namespace std;

//HDF5写功能
class Hdf5WriteValue
{
public:
	hid_t file, dataset, dataspace, group;
	herr_t status;
	hid_t dtype = H5Tcopy(H5T_C_S1);
	
	Hdf5WriteValue(){}; //构造函数
	~Hdf5WriteValue(){};//析构函数
	void CreateNewFile();
	void CreateStringDataspace(const void *data, int rank, int col, int row);
	void CreateDataspace(int rank, int col, int row);
	void CreateGroup(string groupName);
	void CreateIntDataset(string datasetName);
	void CreateDoubleDataset(string datasetName);
	void CreateStringDataset(string datasetName);
	void WriteIntValue(const void *data);
	void WriteDoubleValue(const void *data);
	void WriteStringValue(const void *data);
	void CloseFile();
};

class Hdf5ReadValue
{
public:
	hid_t file, dataset, dataspace, group;
	herr_t status;
	hid_t dtype = H5Tcopy(H5T_C_S1);

	Hdf5ReadValue(){}; //构造函数
	~Hdf5ReadValue(){};//析构函数
	void OpenFile(const char* filepath);
	void OpenGroup(const char* group);
	void OpenDataset(const char* dataset);
	void ReadIntData(void *data);
	void ReadDoubleData(void *data);
	void ReadStringData(void *data);
	void CloseFile();
};
#endif