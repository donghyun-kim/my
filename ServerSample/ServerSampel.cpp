
#include <windows.h>

#include "../Network/Network.h"

int main(int argc, char **argv) 
{
    Network* net = new Network(L"127.0.0.1", 999);
    if (net->Initialize() == false) 
    {
        goto FAILED;
    }
    
    // blocked 
    while (true)
    {
        Sleep(1);
    }
    
    return 0;

FAILED:
    int error_code = -1;
    delete net;

    return error_code;
}
