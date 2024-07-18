#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::vector<int> scores;
    int totalScore;
};

bool compareByTotal(const Student &a, const Student &b) {
    return a.totalScore > b.totalScore;
}

bool compareBySubject(const Student &a, const Student &b, int subjectIndex) {
    return a.scores[subjectIndex] > b.scores[subjectIndex];
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> subjects(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> subjects[i];
    }

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].name;
        students[i].scores.resize(m);
        students[i].totalScore = 0;
        for (int j = 0; j < m; ++j) {
            std::cin >> students[i].scores[j];
            students[i].totalScore += students[i].scores[j];
        }
    }

    std::string sortSubject;
    std::cin >> sortSubject;

    int sortIndex = -1;
    for (int i = 0; i < m; ++i) {
        if (subjects[i] == sortSubject) {
            sortIndex = i;
            break;
        }
    }

    if (sortIndex != -1) {
        std::sort(students.begin(), students.end(), 
                  [sortIndex](const Student &a, const Student &b) {
                      return compareBySubject(a, b, sortIndex);
                  });
    } else {
        std::sort(students.begin(), students.end(), compareByTotal);
    }

    for (const auto &student : students) {
        std::cout << student.name << " ";
        for (int score : student.scores) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
