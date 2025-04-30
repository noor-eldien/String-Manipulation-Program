# String Manipulation using Doubly Linked List

## Overview
This repository contains the implementation of a string manipulation system using a doubly linked list. Each node in the list stores a single character of the string, allowing for efficient manipulation of the string through various operations.

## Features

- **Initialization:** Creates a doubly linked list to store characters of the string.
- **Insertion:** Inserts a character at a specified position in the string.
- **Deletion:** Deletes a character at a specified position in the string.
- **String Length:** Returns the length of the string.
- **Concatenation:** Concatenates two strings represented by doubly linked lists. After the operation, the concatenated string is stored in the first list, and the second list remains unchanged.
- **Substring Extraction:** Extracts a substring from the string given the starting index and length.
- **Search:** Searches for a given substring within the string and returns the starting index of the first occurrence.
- **Replacement:** Replaces occurrences of a substring with another substring within the string.

## Implementation Details

### Node Structure
Each node in the doubly linked list contains:
- A character (`info`).
- A pointer to the next node (`next`).
- A pointer to the previous node (`prev`).

### Class Structure
The `DoublyLinkedList` class manages the nodes and provides the following member functions:
- `insertAt(int position, char c)`: Inserts a character at the specified position.
- `deleteAt(int position)`: Deletes a character at the specified position.
- `length()`: Returns the length of the string.
- `concat(DoublyLinkedList& other)`: Concatenates another string (doubly linked list) to the end of the current string.
- `extractSubstring(int start, int length)`: Returns a substring starting at the given index with the specified length.
- `searchSubstring(const string& sub)`: Searches for a substring and returns the starting index.
- `replaceSubstring(const string& target, const string& replacement)`: Replaces occurrences of a target substring with another substring.

## Program Input/Output Examples

### Input Format

**Example Input:**
```
Enter string to add to list 1: Hello
Enter string to add to list 2: World
Choose a character by a 1-indexed value to remove: 3
Enter index and length to get substring: 
index (1-index value): 2
length: 4
Search for a string in the list: (NOTE: function is Case-Sensitive)
lloW
Enter 2 substrings to replace one with another: 
old string: oWo
new string: XYX
```
### Output Format

**Output:**
```
Concatenated Lists: HelloWorld
String length after concat: 10
List after removal: HeloWorld
Substring: eloW
Found at index 3  -> NOTE: 1-indexed answer
List after replacement: HelXYXrld
```
