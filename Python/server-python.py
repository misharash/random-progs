#!/usr/bin/env python3
import socket

def answer(connc, addrs):
  data = connc.recv(9542)
  print(data.decode("utf-8"))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(("", 9542))
sock.listen(1)

while True:
  conn, addr = sock.accept()
  answer(conn, addr)
  conn.close()