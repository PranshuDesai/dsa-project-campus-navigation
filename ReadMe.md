**IIT Jodhpur Campus Navigation System**



This project is a Data Structures and Algorithms application to find the shortest walking path between any two locations on the IIT Jodhpur campus. It models the campus as a weighted, undirected graph and uses Dijkstra's algorithm to compute the shortest route.

This repository contains two separate, independent implementations of the same project:

&nbsp;\* A C++ Version: A high-performance, command-line-only implementation with a manually-built Dijkstra's algorithm.



&nbsp;\* A Python Version: A high-level, visual implementation that uses the NetworkX and Matplotlib libraries to plot the path on a graph.



&nbsp;**Features:**

&nbsp;\* Models the IITJ campus (locations like B1, G2, LHC1, etc.) as a graph.



&nbsp;\* Finds the shortest path between any two user-specified locations.



&nbsp;\* Calculates and displays the total shortest distance (as walking time in minutes).



&nbsp;\* Displays the step-by-step sequence of locations on the path.



&nbsp;\* C++ Version: Offers a fast, efficient, terminal-based experience, including a simple ASCII map.



&nbsp;\* Python Version: Provides a rich, graphical visualization of the campus map with the shortest path highlighted in red.

&nbsp;Technology Stack



&nbsp;\* C++ Version:

&nbsp;  Language: C++17

&nbsp;  Data Structures: unordered\_map (for adjacency list), vector, priority\_queue (min-heap)

&nbsp;  Algorithm: Manual implementation of Dijkstra's algorithm.

&nbsp;\* Python Version:

&nbsp;  Language: Python 3

&nbsp;  Libraries: networkx (for graph modeling \& algorithms), matplotlib (for plotting)

&nbsp;  Algorithm: networkx.dijkstra\_path()



**How to Run:**



You can run either implementation. They are not connected.



1\. Implementation 1: C++ (Command-Line Version)

This version is a self-contained C++ program. It focuses on a from-scratch implementation of Dijkstra's algorithm for maximum performance and runs entirely in the terminal.

Requirements

&nbsp;\* A C++17 compliant compiler (e.g., g++ or clang++).

Steps



&nbsp;\* Save the code as (for example) main.cpp.



&nbsp;\* Compile the program using your compiler:

&nbsp;  g++ main.cpp -o navigation -std=c++17



&nbsp;\* Run the compiled executable:

&nbsp;  ./navigation



&nbsp;\* Follow the on-screen prompts. You will see an ASCII map, a list of locations, and prompts to enter your source and destination.



Example Output

================ IITJ Campus Navigation System ================



Available Locations:

&nbsp;- B1

&nbsp;- G2

&nbsp;- LHC1

&nbsp;- LHC2

&nbsp;- Library

&nbsp;- Main Gate

&nbsp;- NonVeg Mess

&nbsp;- Sports Complex

&nbsp;- Veg Mess



Enter source: B1

Enter destination: Sports Complex



Shortest Distance: 13 minutes

Path: B1 -> G2 -> Veg Mess -> Sports Complex



**2. Implementation 2: Python (Visual Version)**

This version uses popular Python libraries to not only calculate the path but also generate a graphical plot of the campus map with the shortest route highlighted.

Requirements:

&nbsp;\* Python 3



&nbsp;\* The networkx and matplotlib libraries.

Steps



&nbsp;\* Install the required libraries:

&nbsp;  pip install networkx matplotlib



&nbsp;\* Save the code as (for example) map.py.



&nbsp;\* Run the Python script:

&nbsp;  python map.py



&nbsp;\* Enter the source and destination in the terminal when prompted.



&nbsp;\* Two things will happen:

&nbsp;   The terminal will print the path and distance.

&nbsp;   A new window from Matplotlib will pop up, displaying the campus graph with your shortest path highlighted in red.



Example Output

In your terminal:

Available Locations:

&nbsp;- B1

&nbsp;- G2

&nbsp;- LHC1

&nbsp;- LHC2

&nbsp;- Veg Mess

&nbsp;- NonVeg Mess

&nbsp;- Sports Complex

&nbsp;- Main Gate

&nbsp;- Library



Enter source: B1

Enter destination: Sports Complex



Shortest Distance: 13 minutes

Path: B1 -> G2 -> Veg Mess -> Sports Complex



In the Matplotlib pop-up window:

You will see a graph plot showing all locations and paths, with the path B1 -> G2 -> Veg Mess -> Sports Complex drawn with a thick red line.

