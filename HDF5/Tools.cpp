#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string getLocalTime(string format)
{
	char char_time[64];
	time_t curr_time = time(NULL);
	tm* time_info = std::localtime(&curr_time);
	if (NULL != time_info)
	{
		strftime(char_time, sizeof(char_time), format.c_str(), time_info);
	}
	else
	{
		strcpy(char_time, "NULL");
	}
	return char_time;
}
string hdf5Filename()
{
	string filename_id = "hdf5.out.";
	string time_stamp = getLocalTime("%Y.%m.%d.%H.%M.%S");
	string filename_m = filename_id + time_stamp + ".h5";
	return filename_m;
}