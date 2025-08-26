import sys
from collections import defaultdict

input = sys.stdin.readline

t = int(input())


class Node:
    def __init__(self, value):
        self.value = value
        self.next = {}

    def key_search(self, key):
        return self.next.get(key, None)

    def add_next(self, key, node):
        self.next[key] = node

    def is_end_node_exist(self):
        return self.next.get("END", None) is not None

    def add_end_node(self):
        self.next["END"] = "end"


class Trie:
    def __init__(self):
        self.entries = {}

    def get_entry_node(self, key):
        return self.entries.get(key, None)

    def add_entry_node(self, key, node):
        self.entries[key] = node


def check(phone_numbers):
    trie = Trie()

    for phone_number in phone_numbers:
        if len(phone_number) == 1:
            if trie.get_entry_node(phone_number[0]) is not None:
                return "NO"

        if trie.get_entry_node(phone_number[0]) is not None:
            next_node = trie.get_entry_node(phone_number[0])
            adding_mode = False
            for char in phone_number[1:]:
                if not adding_mode:
                    if next_node.key_search(char) is not None:
                        next_node = next_node.key_search(char)

                    else:
                        if next_node.is_end_node_exist():
                            return "NO"
                        else:
                            next_node.add_next(char, Node(char))
                            next_node = next_node.key_search(char)
                            adding_mode = True
                else:
                    next_node.add_next(char, Node(char))
                    next_node = next_node.key_search(char)

            if not adding_mode:
                return "NO"
            else:
                next_node.add_end_node()

        else:
            next_node = Node(phone_number[0])
            trie.add_entry_node(phone_number[0], next_node)

            for char in phone_number[1:]:
                next_node.add_next(char, Node(char))
                next_node = next_node.key_search(char)

            next_node.add_end_node()
    return "YES"


for _ in range(t):
    n = int(input())
    phone_numbers = [input().strip() for _ in range(n)]
    print(check(phone_numbers))
