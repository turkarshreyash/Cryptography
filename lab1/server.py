import socket      
import threading 
import concurrent.futures

s = socket.socket()          
conn = True


def create_server():
    while True:
        try:
            server_port = int(input("Enter server port number : "))
            addr = input('Enter addr : ')
            s.bind((addr,server_port))  
            s.listen(5)
            break
        except:
            print("Incorrect Number Try Again")
    print(f"Successfully Created Server on : {addr} {server_port}")


def send(c):
    global conn
    while conn:
        message = input(f"Enter Message : ")
        c.send(message.encode()) 

def recv(c):
    global conn
    while conn:
        data = c.recv(1024)
        if data == b'close':
            conn = False
        else:
            print(data.decode())



if __name__ == "__main__":
    create_server()
    while True: 
        c, addr = s.accept()
        conn = True
        t1 = threading.Thread(target=send, args=(c,)) 
        t2 = threading.Thread(target=recv, args=(c,)) 
    
        t1.start() 
        t2.start() 
    
        t1.join() 
        t2.join()
