from multiprocessing.connection import Client
import socket
import json

s = socket.socket()         
s.bind(('0.0.0.0', 7100))
s.listen()                 

while True:
    client, addr = s.accept() # Wait for connection (blocking)
    fullMessage = b''
    while True:
        content = client.recv(32)
        if len(content) ==0:
           break
        else:
            fullMessage = fullMessage + content
    print ('Full Message ' + str(fullMessage) + ' from ' + str({addr[0]}))
    client.close()

    jsonMessage = json.loads(fullMessage) 
    print('Input 1 = ' + str(jsonMessage['input1']) + ' Input 2 = ' + str(jsonMessage['input2']) +
     ' Input 3 = ' + str(jsonMessage['input3']) + ' Input 4 = ' + str(jsonMessage['input4']))
    