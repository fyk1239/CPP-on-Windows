#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    std::ifstream ifs("stream.cpp");
    string buf;
    while (!ifs.eof())
    {
        getline(ifs, buf);
        cout << buf << endl;
    }
    return 0;
}