#pragma once

class Socket 
{
public:
    enum Type
    {
        TCP,
        UDP,
    };

    Socket();
    virtual ~Socket();

    bool Initialize(Type type);

private:
    SOCKET listen_socket_;
};