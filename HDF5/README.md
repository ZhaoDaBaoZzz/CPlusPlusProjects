## 一.开发环境

Visual Studio2013+配置HDF5环境，也可以直接源码和HDF5库CMake编译。

## 二.主要功能

1.HDF5写int,double,string类型的数据到hdf5文件中;

2.读hdf5文件中int,double,string的数据到程序的数据结构中;

3.写数据生成的hdf5文件名使用当前的时间戳来命名。

## 三.文件结构

- Hdf5Function.h

- Tools.h

- Hdf5WriteValue.cpp

- Hdf5ReadValue.cpp

- Tools.cpp

- main.cpp(测试用的主函数)

