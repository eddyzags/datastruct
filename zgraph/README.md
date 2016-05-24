# Zgraph (Graph)

## Introduction

Zgraph is a class that implements a graph. A set of vertices, also called nodes,
connected by edges. The nodes may be part of the graph or may be external entities.
There are several ways to represent a graph in memory. Zgraph uses the adjacent
representation (For each vertex, store a list of vertices adjacent to it)

## Features

### Modifiers

`void add_vertex(const zType &vertex)`  
Add a new vertex to the graph. If it exists, this function does nothing  
Complexity: constant

`void add_edge(const zType &vertex_u, const zType &vertex_v)`  
Add an edge between two vertices. The two vertices become adjacent.  
Complexity: Number of degree

`void remove_vertex(const zType &vertex)`  
Remove one vertex from the graph. All his connections will be removed.

`void remove_edge(const zType &vertex_u, const zType &vertex_y)`  
Remove one edge from two vertices. They are no longer adjacent.
