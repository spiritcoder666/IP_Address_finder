# IP_Address_finder

This project implements a **Splay Tree** in C++, a self-adjusting binary search tree that performs rotations to bring accessed nodes closer to the root. The implementation includes basic operations like insertion, searching, and in-order traversal, with the functionality demonstrated using IP addresses and randomly generated data packets.

## Features

- **Node Operations**:
  - Insert nodes into the Splay Tree.
  - Search for nodes and bring them to the root using the splay operation.
  - Perform in-order traversal to display the tree content.

- **Custom Data**:
  - Each node represents an IP address with a randomly generated data packet.

- **Tree Rotations**:
  - Left and right rotations for tree restructuring.

## Files

- `main.cpp`: Contains the source code for the Splay Tree implementation.
- `README.md`: Documentation for the project.

## Requirements

- C++ compiler (e.g., g++, clang++)
- Compatible operating system (Windows, Linux, or macOS)

## How It Works

1. Nodes are inserted into the tree with unique IP addresses.
2. Random data packets are generated for each IP address.
3. A search operation moves the accessed node to the root using splay operations.
4. The in-order traversal displays the IP addresses and their corresponding data packets in sorted order.

## Usage

1. Clone the repository:
   ```bash
   [git clone https://github.com/spiritcoder666/splay-tree-cpp.git
   cd splay-tree-cpp](https://github.com/spiritcoder666/IP_Address_finder.git)
 ## Compile the program:
 g++ main.cpp -o splay_tree

##Run amd executable:
./splay_tree

## Sample Output
IP ADDRESS -> DATA PACKET
192.168.3.104 -> 57
192.168.3.108 -> 142
192.168.3.109 -> 65
192.168.3.111 -> 23
192.168.3.112 -> 98
192.168.3.117 -> 54
192.168.3.121 -> 172
192.168.3.122 -> 99
192.168.3.124 -> 67
192.168.3.125 -> 36
192.168.3.129 -> 88

 
 

