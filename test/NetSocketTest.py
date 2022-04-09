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
            print(content)
 
    print(f"Closing connection {addr}")
    client.close()
