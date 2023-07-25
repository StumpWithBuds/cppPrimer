#include <iostream>
#include <memory>
#include <string>

struct connection {
    std::string ip;
    int port;
    connection(std::string ip, int port): ip(ip), port(port) {}
};

struct destination {
    std::string ip;
    int port;
    destination(std::string ip, int port): ip(ip), port(port) {}
};

connection connect(destination* desP) {
    std::shared_ptr<connection> conP(new connection(desP->ip, desP->port));
    std::cout << "creating connection(" << conP.use_count() << ")" << std::endl;
    return *conP;
}

void disconnect(connection pConn)
{
	std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;	
}

void end_connection(connection* pConn)
{
	disconnect(*pConn);
}

void f(destination &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> conP(&c, end_connection);
    std::cout << "connected now " << conP.use_count() << std::endl; 
}

int main() {
    destination dest("220.181.111.111", 10086);
	f(dest);
	return 0;
}