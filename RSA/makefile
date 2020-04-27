test: driver.cpp RSA.cpp
	g++ -o test driver.cpp RSA.cpp

server: server.cpp RSA.cpp udp.cpp
	g++ -o server server.cpp udp.cpp RSA.cpp

client: client.cpp RSA.cpp udp.cpp
	g++ -o client client.cpp udp.cpp RSA.cpp

signatureserver: signatureserver.cpp RSA.cpp udp.cpp
	g++ -o signatureserver signatureserver.cpp udp.cpp RSA.cpp

signatureclient: signatureclient.cpp RSA.cpp udp.cpp
	g++ -o signatureclient signatureclient.cpp udp.cpp RSA.cpp