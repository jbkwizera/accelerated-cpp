from collections import Counter

WEIGHTS = dict.fromkeys("abcdefghijklmnopqrstuvwxyz", 0)


class Node:
    def __init__(self) -> None:
        self.val = None
        self.next = [None] * 26


class Trie:
    def __init__(self):
        self.root = None

    def insert(self, key, val):
        def _insert(x, key, val, d):
            if x is None:
                x = Node()
            if d == len(key):
                x.val = val
                return x
            c = ord(key[d]) - 97
            x.next[c] = _insert(x.next[c], key, val, d + 1)
            return x

        self.root = _insert(self.root, key, val, 0)

    # def get(self, key):
    #     def _get(x, key, d):
    #         if x is None:
    #             return None
    #         if d == len(key):
    #             return x
    #         c = ord(key[d]) - 97
    #         return _get(x.next[c], key, d + 1)
    #
    #     x = _get(self.root, key, 0)
    #     if x is None:
    #         return None
    #     return x.val t

    # def contains(self, key):
    #     return self.get(key) is not None

    def max_scoring(self, word):
        counter = Counter(word)

        def traverse(x, curr, best, counter):
            if x.val is not None:
                if x.val > best[1]:
                    best[0] = curr
                    best[1] = x.val
                elif x.val == best[1]:
                    best[0] = min(best[0], curr)

            for ch in counter:
                c = ord(ch) - 97
                if x.next[c] and counter[ch]:
                    counter[ch] -= 1  # use up this char for current sub-trie
                    traverse(x.next[c], curr + ch, best, counter)
                    counter[ch] += 1  # restore counter for sibling sub-tries
            return best

        return traverse(self.root, "", ["", 0], counter)


def main():
    with open("./tdata/score.txt", "r") as file:
        for line in file.readlines()[1:]:
            ch, score = line.strip().split(",")
            WEIGHTS[ch.strip().lower()] = int(score.strip())

    def word_value(word):
        return sum([WEIGHTS[_] for _ in word])

    trie = Trie()

    with open("./tdata/dictionary_2.txt", "r") as file:
        for line in file.readlines():
            word = line.strip().lower()
            trie.insert(word, word_value(word))

    with open("./tdata/test_random_string_500.txt", "r") as file:
        for line in file.readlines():
            word = line.strip().lower()
            best = trie.max_scoring(word)
            print(f"{word}, {best[0]}, {best[1]}")


if __name__ == "__main__":
    """
    You should think of your peers as other managers, people in your PROFESSION,
    people in your WORK GROUP, people in your CLASSES, or people you interact
    with on a regular basis, etc
    """
    main()
