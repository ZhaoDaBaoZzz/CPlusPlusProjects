#include "Tools.h"
#include "Hdf5Function.h"
using namespace std;

Hdf5ReadValue::Hdf5ReadValue(){}; //构造函数
Hdf5ReadValue::~Hdf5ReadValue(){};//析构函数

/*打开HDF5文件*/
void Hdf5ReadValue::OpenFile(const char* filepath)
{
	this->file = H5Fopen(filepath, H5F_ACC_RDONLY, H5P_DEFAULT);
}

/*打开HDF5文件对应的Group*/
void Hdf5ReadValue::OpenGroup(const char* group)
{
	this->group = H5Gopen2(this->file, group, H5P_DEFAULT);
}

/*打开HDF5文件对应的Dataset*/
void Hdf5ReadValue::OpenDataset(const char* dataset)
{
	this->dataset = H5Dopen(this->group, dataset, H5P_DEFAULT);
}

/*读文件中的各种类型数据int,double,string*/
void Hdf5ReadValue::ReadIntData(void *data)
{
	this->status = H5Dread(this->OpenDataset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);
}

void Hdf5ReadValue::ReadDoubleData(void *data)
{
	this->status = H5Dread(this->OpenDataset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);
}

void Hdf5ReadValue::ReadStringData(void *data)
{
	size_t size = sizeof(data) / sizeof(char);
	this->status = H5Test_size(dtype, size);
	this->status = H5Dread(this->OpenDataset, this->dtype, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);
}

/*关闭数据及文件*/
void Hdf5ReadValue::CloseFile()
{
	this->status = H5Dclose(this->dataset);
	this->status = H5Gclose(this->group);
	this->status = H5Fclose(this->file);
}