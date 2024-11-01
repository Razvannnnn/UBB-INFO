import socket
import struct

def main():
    server_address = ('127.0.0.1', 1234)

    # TCP
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        try:
            client_socket.connect(server_address)
        except Exception as e:
            print("Error connecting to the server:", e)
            return

        a = input("Primul sir = ")
        b = input("Al doilea sir = ")

        client_socket.sendall(a.encode().ljust(256, b'\x00'))
        client_socket.sendall(b.encode().ljust(256, b'\x00'))

        chr_data = client_socket.recv(2)
        chr_received = chr_data.decode().strip('\x00')

        rez_data = client_socket.recv(2)
        rez = struct.unpack('!H', rez_data)[0]  #ntoh

        if rez == 0:
            print("Nu s-a gasit un caracter comun")
        else:
            print(f"Caracterul: {chr_received}, nr aparitii: {rez}")

if __name__ == "__main__":
    main()
