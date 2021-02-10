#include <lcq.hpp>
#include <string>
#include <fstream>

using namespace std;

void readingFromFile(string file = "file1.txt")
{
    int a;
    ifstream infile(file);
    while (infile >> a)
    {
        // process as per ypur wishes
    }
}

int main(int argc, char *argv[])
{
    for(int i=1; i <= argc; i++) // i=1, assuming files arguments are right after the executable
    {
        string fn = argv[i]; //filename
        readingFromFile(fn);
    }
    return EXIT_SUCCESS;
}