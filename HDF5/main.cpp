#include <windows.h>
#include <fstream>
#include "Hdf5Function.h"

int main()
{
	/*测试代码*/
	//一维int
	const int a = 99;
	const int*value1 = &a;
	//一维double
	const double b = 99.99;
	const double* value2 = &b;
	//一维char
	const char* value3 = "abc";
	//二维intle数组
	int value4[5][6];
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			value4[i][j] = i + j;
		}
	}
	//二维double数组
	double value5[289][28];
	int i, j;
	for (i = 0; i < 289; i++)
	{
		for (j = 0; j < 28; j++)
		{
			value5[i][j] = 0.1 + i + j;
		}
	}

	//存放读数据的数据结构
	double* result = new double[289 * 28];
	char* result1 = new char[20];

	//同一个文件内写数据
	Hdf5WriteValue write;
	write.CreateNewFile();
	//写一个int数据
	write.CreateDataspace(1, 0, 1);
	write.CreateGroup("groupA");
	write.CreateIntDataset("datasetA");
	write.WriteIntValue(value1);
	//写一个double数据
	write.CreateDoubleDataset("datasetB");
	write.WriteDoubleValue(value2);
	//新建一个group写一个string数据
	write.CreateGroup("groupB");
	write.CreateStringDataspace(value3,1, 0, 1);
	write.CreateStringDataset("datasetC");
	write.WriteStringValue(value3);
	//写一个int二维数组
	write.CreateDataspace(2, 5, 6);
	write.CreateIntDataset("datasetD");
	write.WriteIntValue(value4);
	//写一个double二维数组
	write.CreateDataspace(2, 289, 28);
	write.CreateDoubleDataset("datasetE");
	write.WriteDoubleValue(value5);

	write.CloseFile();

	//读H5或HDF5文件
	Hdf5ReadValue read;
	//读double数据
	char filename[] = "hdf5.h5";
	read.OpenFile(filename);
	read.OpenGroup("groupB");
	read.OpenDataset("datasetE");
	read.ReadDoubleData(result);
	//打印测试
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	for (i = 0; i < 8092; i++)
	{
		cout << result[i] << endl;
	}

	//读取字符串数据
	read.OpenGroup("groupB");
	read.OpenDataset("datasetC");
	read.ReadStringData(result1);
	cout << result1 << endl;

	read.CloseFile();
	delete result;
	delete result1;
	system("pause");
	return 0;

}