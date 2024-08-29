#include <string>
#include <unordered_map>

class Trie {
  private:
    std::unordered_map<char, Trie*> children;
    bool is_word;

  public:
    Trie() { is_word = false; }

    void insert(std::string word) {
        auto current = this;

        for (const auto& ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new Trie();
            }

            current = current->children[ch];
        }

        current->is_word = true;
    }

    bool search(std::string word) {
        auto current = this;

        for (const auto& ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }

            current = current->children[ch];
        }

        return current->is_word;
    }

    bool startsWith(std::string prefix) {
        auto current = this;

        for (const auto& ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }

            current = current->children[ch];
        }

        return true;
    }
};
