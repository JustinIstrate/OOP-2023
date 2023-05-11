#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <fstream>
#include <filesystem>
using namespace std;

class CommandManager {
  private:
    map<string, function<void(vector<string>)>> commands;

  public:
    void add(string name, function<void(vector<string>)> fn);
    void run();
};

class FileException : public std::exception {
  private:
    string filename;
    string message;

  public:
    FileException(const std::string& filename, const std::string& message);
    virtual const char* what() const noexcept override;
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    string tmp;
    vector<string> args;

    while (true) {
        printf("\n");
        getline(cin, tmp);
        args.clear();
        auto ptr = strtok(&tmp[0], " ");
        while (ptr) {
            args.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (args.empty()) {
            // empty command, doing nothing
            continue;
        }

        auto command = args[0];
        if (command == "stop") {
            return;
        }
        auto it = commands.find(command);
        if (it == commands.end()) {
            printf("no command with that name: %s\n", command.c_str());
            continue;
        }

        // remove the command name
        args.erase(args.begin());

        try {
            it->second(args);
        } catch (std::exception& e) {
            fprintf(stderr, "command `%s` failed: %s\n", command.c_str(), e.what());
        }
    }
}

int main() {
    CommandManager manager;
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);
    // ping({ "mmm", "bb" });
    auto count = [](vector<string> args) { printf("counted %zu args\n", args.size()); };
    // count({ "aana", "aefbaj", "asjlksv", "assvsad" });
    manager.add("count", count);
    int a = 0;
    auto times = [a](vector<string> args) mutable {
        a++;
        printf("%d \n", a);
    };
    // times({ "assvsd", "asfv" });
    manager.add("times", times);
    string line;
    auto copy = [](vector<string> args) {
        filesystem::remove(args[1]);
        filesystem::copy_file(args[0], args[1]);
    };
    manager.add("copy", copy);
    // copy({ "image.png", "output.png" });

    auto vowels = [nr = 0](vector<string> args) mutable {
        for (auto it = args.begin(); it != args.end(); ++it) {
            string key = *it;
            nr = 0;
            for (int i = 0; i < key.size(); i++)
                if (strchr("aeiou", key[i]))
                    nr++;
            printf("nr of vowels for '%s' is %d \n", key.c_str(), nr);
        }
    };
    // vowels({ "ana", "are", "mere", "ccc" });
    manager.add("vowels", vowels);
    manager.run();

    printf("goodbye.\n");
}
