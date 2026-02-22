# Prim algorithm C++

## Project Description

This project implements **Prim's algorithm** for finding the Minimum Spanning Tree (MST) of a weighted undirected graph. Two different data structure implementations are provided:

- **PrimL**: Implementation using linked lists
- **PrimM**: Implementation using adjacency matrices

The project includes a graph parser that reads graphs from text files and a chronometer to measure algorithm execution time.

## Features

- Two implementations of Prim's algorithm (List-based and Matrix-based)
- Graph parsing from text files
- Connectivity checking
- Execution time measurement
- Test graphs included

## Building the Project

### Prerequisites
- C++17 compiler (g++ or compatible)
- Make

### Build Instructions

```bash
# Build both PrimL and PrimM executables
make

# Clean build artifacts
make clean
```

This will generate two executable files: `PrimL` and `PrimM`

## Running the Project

Both executables require a graph file and a starting vertex as arguments:

```bash
# Using list-based implementation
./PrimL <graph_file> <starting_vertex>

# Using matrix-based implementation
./PrimM <graph_file> <starting_vertex>
```

### Example Usage

```bash
./PrimL graph.txt 1
./PrimM graph2.txt 1
```

### Graph Input Format

The graph file should contain:
- First line: degree of the graph (number of vertices)
- Following lines: adjacency information in the format `current_vertex target_vertex weight ...`

Test graph files are provided: `graph.txt`, `graph2.txt`, `graph3.txt`

## Output

The program displays:
- Whether the graph is connected or not
- For each vertex: its predecessor in the MST and the edge weight
- Total cost of the minimum spanning tree