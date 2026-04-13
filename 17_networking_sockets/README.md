# Lesson 17: Networking and Sockets

Every time you type a URL into your browser, you are fundamentally sending text over the internet to a C program listening on a **Socket**.

## What is a Socket?
A Socket is a programming interface provided by the Operating System that allows software to send data over a network. In Unix/Linux, a Socket is literally treated as a **File Descriptor** (just like we used when writing to the Hard Drive). Writing to a Socket pushes bytes through the physical internet cable!

## The Lifecycle of a Web Server
To build a basic HTTP web server, we need to execute 4 steps:
1. **`socket()`**: Ask the OS to create an internet socket.
2. **`bind()`**: Bind the socket to a specific Port on your machine (e.g., Port `8080`).
3. **`listen()`**: Tell the OS to actively listen for incoming connections from the outside world.
4. **`accept()`**: When a browser connects, the OS hands us their connection. We can now `read()` their HTTP request and `write()` back an HTML response!

## HTTP Protocol
When a browser connects, it will literally send us raw text that looks like this:
```
GET / HTTP/1.1
Host: localhost:8080
```
To "be a server", we just have to capture that text, and write back this raw text:
```
HTTP/1.1 200 OK
Content-Type: text/plain

Hello from my Custom C Server!
```

Check out `main.c` where we will build a micro web server in under 50 lines of code!
