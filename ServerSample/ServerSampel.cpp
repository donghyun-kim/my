
#include <windows.h>

#include "../Network/Network.h"

#ifdef _DEBUG
    #pragma comment(lib, "../x64/Debug/Network.lib")
#else
    #pragma comment(lib, "../x64/Release/Network.lib")
#endif

int main(int argc, char **argv) 
{
    Network net(L"127.0.0.1", 999);
    
    while (true)
    {

    }

    return 0;
}
