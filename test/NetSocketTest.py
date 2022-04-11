from multiprocessing.connection import Client
import socket
s = socket.socket()         
s.bind(('0.0.0.0', 7100))
s.listen()                 

while True:

    client, addr = s.accept()
    while True:
        content = client.recv(32)
        if len(content) ==0:
           break
        else:
            print("Received ")
            print(content)
            if(addr[0] == "192.168.0.69"):
                client.sendall(b"Thank you number 3")            
    print(f"Closing connection {addr[0]}")
    client.close()
