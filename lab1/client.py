import socket                
import threading 

s = socket.socket()          
  
def connect_to_server():
    while True:
        try:
            server_port = int(input("Enter server port number : "))
            addr = input('Enter addr : ')
            s.connect((addr, server_port))
            break
        except:
            print("Incorrect Number Try Again")
    print(f"Successfully Connected to : {addr} {server_port}")

def send():
    while True:
        message = input("Enter Message : ")
        s.send(message.encode())
        if message == "close":
            exit()

def recv():
    while True:
        print(s.recv(1024).decode())

if __name__ == "__main__":
    connect_to_server()
    t1 = threading.Thread(target=send, args=()) 
    t2 = threading.Thread(target=recv, args=()) 
  
    t1.start() 
    t2.start() 
  
    t1.join() 
    t2.join()