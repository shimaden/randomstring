#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdio>

namespace {

void show_usage()
{
    std::cout << "Usage: randomstring characters\n"
              << "    This process takes some times." << std::endl;
}

bool check_args(int argc, char *argv[], int& count)
{
    if(argc != 2)
    {
        return false;
    }

    int n = ::sscanf(argv[1], "%d", &count);
    if(n != 1)
    {
        return false;
    }

    return count > 0;
}

} /* anonymous namespace */

int main(int argc, char *argv[])
{
    int count;

    if(check_args(argc, argv, count))
    {
        std::ifstream f("/dev/random", std::ios::in | std::ios::binary);
        if(!f.is_open())
        {
            std::cerr << "Can't open \"/dev/random\"" << std::endl;
            return 1;
        }

        int out = 0;
        while(out < count)
        {
            char c;
            f.read(&c, 1);
            c = c & 0x7F;
            if(isalnum(c))
            {
                std::cout << c << std::flush;
                ++out;
            }
        }
        std::cout << std::endl;

        f.close();
    }
    else
    {
        show_usage();

        return 1;
    }

    return 0;
}
